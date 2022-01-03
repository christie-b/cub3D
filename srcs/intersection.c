/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:57:19 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/17 13:19:46 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	ft_next_hor_touch(t_total *total, int i)
{
	double	next_hor_touch_x;
	double	next_hor_touch_y;
	double	adj;

	next_hor_touch_x = total->ray[i]->x_intercept;
	next_hor_touch_y = total->ray[i]->y_intercept;
	while (next_hor_touch_x >= 0 && next_hor_touch_x <= WIN_W
		&& next_hor_touch_y >= 0 && next_hor_touch_y <= WIN_H)
	{
		adj = ft_get_adjustment(total->ray[i]->ray_facing_down);
		if (has_wall(next_hor_touch_x, next_hor_touch_y - adj, total))
		{
			total->ray[i]->found_hor_wall_hit = 1;
			total->ray[i]->hor_wall_hit_x = next_hor_touch_x;
			total->ray[i]->hor_wall_hit_y = next_hor_touch_y;
			break ;
		}
		else
		{
			next_hor_touch_x += total->ray[i]->x_step;
			next_hor_touch_y += total->ray[i]->y_step;
		}
	}
}

void	ft_horizontal_intercept(t_total *total, int i)
{
	total->ray[i]->y_intercept = floor(total->player->pos_pix_y
			/ MINI_TILE_SIZE) * MINI_TILE_SIZE;
	if (total->ray[i]->ray_facing_down == 1)
		total->ray[i]->y_intercept += MINI_TILE_SIZE;
	total->ray[i]->x_intercept = total->player->pos_pix_x
		+ (total->ray[i]->y_intercept - total->player->pos_pix_y)
		/ tan(total->ray[i]->ray_angle);
	total->ray[i]->y_step = MINI_TILE_SIZE;
	if (total->ray[i]->ray_facing_down == 0)
		total->ray[i]->y_step *= -1;
	total->ray[i]->x_step = MINI_TILE_SIZE / tan(total->ray[i]->ray_angle);
	if (total->ray[i]->ray_facing_right == 0 && total->ray[i]->x_step > 0)
		total->ray[i]->x_step *= -1;
	if (total->ray[i]->ray_facing_right == 1 && total->ray[i]->x_step < 0)
		total->ray[i]->x_step *= -1;
	ft_next_hor_touch(total, i);
}

void	ft_next_vert_touch(t_total *total, int i)
{
	double	next_vert_touch_x;
	double	next_vert_touch_y;
	double	adj;

	adj = 0.0;
	next_vert_touch_x = total->ray[i]->x_intercept;
	next_vert_touch_y = total->ray[i]->y_intercept;
	while (next_vert_touch_x >= 0 && next_vert_touch_x <= WIN_W
		&& next_vert_touch_y >= 0 && next_vert_touch_y <= WIN_H)
	{
		adj = ft_get_adjustment(total->ray[i]->ray_facing_right);
		if (has_wall(next_vert_touch_x - adj, next_vert_touch_y, total))
		{
			total->ray[i]->found_vert_wall_hit = 1;
			total->ray[i]->vert_wall_hit_x = next_vert_touch_x;
			total->ray[i]->vert_wall_hit_y = next_vert_touch_y;
			break ;
		}
		else
		{
			next_vert_touch_x += total->ray[i]->x_step;
			next_vert_touch_y += total->ray[i]->y_step;
		}
	}
}

void	ft_vertical_intercept(t_total *total, int i)
{
	total->ray[i]->x_intercept = floor(total->player->pos_pix_x
			/ MINI_TILE_SIZE) * MINI_TILE_SIZE;
	if (total->ray[i]->ray_facing_right == 1)
		total->ray[i]->x_intercept += MINI_TILE_SIZE;
	total->ray[i]->y_intercept = total->player->pos_pix_y
		+ (total->ray[i]->x_intercept - total->player->pos_pix_x)
		* tan(total->ray[i]->ray_angle);
	total->ray[i]->x_step = MINI_TILE_SIZE;
	if (total->ray[i]->ray_facing_right == 0)
		total->ray[i]->x_step *= -1;
	total->ray[i]->y_step = MINI_TILE_SIZE * tan(total->ray[i]->ray_angle);
	if (total->ray[i]->ray_facing_down == 0 && total->ray[i]->y_step > 0)
		total->ray[i]->y_step *= -1;
	if (total->ray[i]->ray_facing_down == 1 && total->ray[i]->y_step < 0)
		total->ray[i]->y_step *= -1;
	ft_next_vert_touch(total, i);
}

void	ft_store_smallest_dist(t_total *total, double hor_hit_distance, \
double vert_hit_distance, int i)
{
	if (hor_hit_distance < vert_hit_distance)
		total->ray[i]->wall_hit_x = total->ray[i]->hor_wall_hit_x;
	else
		total->ray[i]->wall_hit_x = total->ray[i]->vert_wall_hit_x;
	if (hor_hit_distance < vert_hit_distance)
		total->ray[i]->wall_hit_y = total->ray[i]->hor_wall_hit_y;
	else
		total->ray[i]->wall_hit_y = total->ray[i]->vert_wall_hit_y;
	if (hor_hit_distance < vert_hit_distance)
		total->ray[i]->distance = hor_hit_distance;
	else
		total->ray[i]->distance = vert_hit_distance;
	total->ray[i]->ray_length = total->ray[i]->distance;
	if (vert_hit_distance < hor_hit_distance)
		total->ray[i]->was_hit_vert = 1;
	else
		total->ray[i]->was_hit_vert = 0;
}
