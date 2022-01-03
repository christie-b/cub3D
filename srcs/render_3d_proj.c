/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_proj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 09:35:33 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/21 13:44:14 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	ft_draw_wall(t_total *total, int i, t_image *texture)
{
	int		j;
	double	y_off;
	double	x_off;
	double	ref;

	if (total->ray[i]->was_hit_vert == 0)
		x_off = fmod(total->ray[i]->wall_hit_x * ((double)texture->width
					/ (double)MINI_TILE_SIZE), (double)texture->width);
	else
		x_off = fmod(total->ray[i]->wall_hit_y * ((double)texture->width
					/ (double)MINI_TILE_SIZE), (double)texture->width);
	if (total->wall->height > WIN_H)
		y_off = (total->wall->height / 2.0) - (WIN_H / 2.0);
	else
		y_off = 0;
	if (total->wall->height > WIN_H)
		ref = WIN_H;
	else
		ref = total->wall->height;
	j = -1;
	while (++j < ref)
		my_mlx_pixel_put(total->image, i, total->wall->y + j,
			get_pixel_color(texture, x_off, ((y_off++) * texture->height)
				/ total->wall->height));
}

t_image	*ft_get_wall_texture(t_total *total, int i)
{
	if (total->ray[i]->was_hit_vert == 0)
	{
		if (total->ray[i]->ray_facing_down == 0)
			return (total->img_north);
		else
			return (total->img_south);
	}
	else
	{
		if (total->ray[i]->ray_facing_right == 0)
			return (total->img_west);
		else
			return (total->img_east);
	}
}

void	ft_render_3d_proj_walls(t_total *total)
{
	int		i;
	double	wall_strip_height;
	double	distance_proj_plane;
	double	correct_ray_dist;

	i = 0;
	while (i < WIN_W)
	{
		correct_ray_dist = total->ray[i]->ray_length
			* cos(total->ray[i]->ray_angle - total->player->rotation_angle);
		distance_proj_plane = (WIN_W / 2) / tan(total->fov_angle / 2);
		wall_strip_height = (MINI_TILE_SIZE / correct_ray_dist)
			* distance_proj_plane;
		total->wall->height = wall_strip_height;
		total->wall->x = i;
		total->wall->y = (WIN_H / 2) - (wall_strip_height / 2);
		if (total->wall->y < 0)
			total->wall->y = 0;
		ft_draw_wall(total, i, ft_get_wall_texture(total, i));
		i++;
	}
}
