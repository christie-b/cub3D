/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:07:00 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/22 10:36:59 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	ft_calculate_intercept(t_total *total, double ray_angle, int i)
{
	total->ray[i]->ray_angle = ft_normalize_angle(ray_angle);
	total->ray[i]->wall_hit_x = 0;
	total->ray[i]->wall_hit_y = 0;
	total->ray[i]->distance = 0;
	total->ray[i]->found_vert_wall_hit = 0;
	total->ray[i]->found_hor_wall_hit = 0;
	if (total->ray[i]->ray_angle > 0 && total->ray[i]->ray_angle < PI)
		total->ray[i]->ray_facing_down = 1;
	else
		total->ray[i]->ray_facing_down = 0;
	if (total->ray[i]->ray_angle < 0.5 * PI
		|| total->ray[i]->ray_angle > 1.5 * PI)
		total->ray[i]->ray_facing_right = 1;
	else
		total->ray[i]->ray_facing_right = 0;
	ft_horizontal_intercept(total, i);
	ft_vertical_intercept(total, i);
	ft_calculate_distance(total, i);
}

void	ft_print_rays(t_total *total, double ray_angle, int i)
{
	double	n;
	double	hypo;

	n = 0;
	hypo = distance_between_points(total->ray[i]->wall_hit_x,
			total->ray[i]->wall_hit_y, total->player->pos_pix_x,
			total->player->pos_pix_y);
	while (n < hypo)
	{
		if ((total->player->pos_pix_x + (cos(ray_angle) * (hypo - n)))
			< WIN_W
			&& (total->player->pos_pix_y + (sin(ray_angle) * (hypo - n)))
			< WIN_H)
		{
			my_mlx_pixel_put (total->image,
				total->player->pos_pix_x + (cos(ray_angle) * (hypo - n)),
				total->player->pos_pix_y + (sin(ray_angle) * (hypo - n)),
				PURPLE);
		}
		n++;
	}
}

void	ft_cast_rays(t_total *total)
{
	double	ray_angle;
	int		i;
	int		nb_rays;

	ray_angle = total->player->rotation_angle - (total->fov_angle / 2);
	nb_rays = WIN_W;
	i = 0;
	while (i < nb_rays)
	{
		total->ray[i]->ray_angle = ray_angle;
		ft_calculate_intercept(total, total->ray[i]->ray_angle, i);
		ray_angle += total->fov_angle / nb_rays;
		i++;
	}
}

void	ft_calculate_distance(t_total *total, int i)
{
	double	hor_hit_distance;
	double	vert_hit_distance;

	hor_hit_distance = 0.0;
	vert_hit_distance = 0.0;
	if (total->ray[i]->found_hor_wall_hit)
	{
		hor_hit_distance = distance_between_points(total->player->pos_pix_x,
				total->player->pos_pix_y, total->ray[i]->hor_wall_hit_x,
				total->ray[i]->hor_wall_hit_y);
	}
	else
		hor_hit_distance = 2147483647.0;
	if (total->ray[i]->found_vert_wall_hit)
	{
		vert_hit_distance = distance_between_points(total->player->pos_pix_x,
				total->player->pos_pix_y, total->ray[i]->vert_wall_hit_x,
				total->ray[i]->vert_wall_hit_y);
	}
	else
		vert_hit_distance = 2147483647.0;
	ft_store_smallest_dist(total, hor_hit_distance, vert_hit_distance, i);
}

int	has_wall(double x, double y, t_total *total)
{
	int	map_pos_x;
	int	map_pos_y;

	map_pos_y = 0;
	map_pos_x = 0;
	if (x < 0 || x > WIN_W || y < 0 || y > WIN_H)
		return (1);
	map_pos_x = floor(x / MINI_TILE_SIZE);
	if (map_pos_x < 0)
		map_pos_x = 0;
	if (map_pos_x > total->info->map_width - 1)
		map_pos_x = total->info->map_width - 1;
	map_pos_y = floor(y / MINI_TILE_SIZE);
	if (map_pos_y < 0)
		map_pos_y = 0;
	if (map_pos_y > total->info->map_height - 1)
		map_pos_y = total->info->map_height - 1;
	if (total->info->map[map_pos_y][map_pos_x] == '1')
		return (1);
	return (0);
}
