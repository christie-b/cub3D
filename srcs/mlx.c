/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:00:25 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/22 10:37:04 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	ft_create_window(t_window *window, char *title)
{
	window->mlx_ptr = mlx_init();
	if (window->mlx_ptr == 0)
		return (1);
	window->win_ptr = mlx_new_window(window->mlx_ptr, WIN_W, WIN_H, title);
	if (window->win_ptr == 0)
	{
		free (window->mlx_ptr);
		return (1);
	}
	return (0);
}

int	ft_close_window(t_total *total)
{
	mlx_destroy_image(total->window->mlx_ptr, total->image->img);
	mlx_destroy_image(total->window->mlx_ptr, total->img_west->img);
	mlx_destroy_image(total->window->mlx_ptr, total->img_east->img);
	mlx_destroy_image(total->window->mlx_ptr, total->img_north->img);
	mlx_destroy_image(total->window->mlx_ptr, total->img_south->img);
	free(total->image);
	free(total->img_east);
	free(total->img_west);
	free(total->img_north);
	free(total->img_south);
	if (total->window && total->window->mlx_ptr)
	{
		if (total->window->mlx_ptr)
			mlx_destroy_window(total->window->mlx_ptr, total->window->win_ptr);
		mlx_destroy_display(total->window->mlx_ptr);
		free(total->window->mlx_ptr);
		total->window->mlx_ptr = NULL;
	}
	ft_free(total->info);
	exit(0);
}

void	ft_update_new_pos(t_total *total, double axis_step, double lat_step)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = total->player->pos_pix_x + cos(total->player->rotation_angle)
		* axis_step;
	new_pos_y = total->player->pos_pix_y + sin(total->player->rotation_angle)
		* axis_step;
	new_pos_x += cos(total->player->rotation_angle + PI / 2) * lat_step;
	new_pos_y += sin(total->player->rotation_angle + PI / 2) * lat_step;
	if (total->info->map[(int)(total->player->pos_pix_y / MINI_TILE_SIZE)]
		[(int)floor(new_pos_x / MINI_TILE_SIZE +0.25)] != '1'
		&& total->info->map[(int)(total->player->pos_pix_y / MINI_TILE_SIZE)]
		[(int)floor(new_pos_x / MINI_TILE_SIZE - 0.25)] != '1')
		total->player->pos_pix_x = new_pos_x;
	if (total->info->map[(int)floor(new_pos_y / MINI_TILE_SIZE + 0.25)]
		[(int)(total->player->pos_pix_x / MINI_TILE_SIZE)] != '1'
		&& total->info->map[(int)floor(new_pos_y / MINI_TILE_SIZE - 0.25)]
		[(int)(total->player->pos_pix_x / MINI_TILE_SIZE)] != '1')
		total->player->pos_pix_y = new_pos_y;
}

void	ft_update_player_pos(t_total *total)
{
	double	axis_step;
	double	lat_step;

	axis_step = (total->player->mov_up - total->player->mov_down)
		* total->player->move_speed;
	lat_step = (total->player->mov_right - total->player->mov_left)
		* total->player->move_speed;
	total->player->rotation_angle += (total->player->rot_right
			- total->player->rot_left) * total->player->rotation_speed;
	total->player->rotation_angle = ft_normalize_angle
		(total->player->rotation_angle);
	ft_update_new_pos(total, axis_step, lat_step);
}

int	ft_mlx(t_total *total)
{
	ft_bzero(total->image->img_ptr, WIN_W * WIN_H * 4);
	ft_update_player_pos(total);
	ft_print_ceil_and_floor(total);
	ft_render_3d_proj_walls(total);
	ft_cast_rays(total);
	mlx_put_image_to_window(total->window->mlx_ptr,
		total->window->win_ptr, total->image->img, 0, 0);
	return (0);
}
