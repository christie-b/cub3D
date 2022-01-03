/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_wall_images.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:37:03 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/22 09:44:49 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	ft_north_image(t_total *total)
{
	total->img_north = ft_calloc(sizeof(t_image), 1);
	if (total->img_north == 0)
		return (0);
	total->img_north->img = mlx_xpm_file_to_image(total->window->mlx_ptr,
			total->info->north_path, &total->img_north->width,
			&total->img_north->height);
	if (total->img_north->img == 0)
		return (ft_free_images(total, total->img_north, 0));
	total->img_north->img_ptr = mlx_get_data_addr(total->img_north->img,
			&total->img_north->bpp, &total->img_north->line_length,
			&total->img_north->endian);
	if (total->img_north->img_ptr == 0)
		return (ft_free_images(total, total->img_north, 0));
	return (0);
}

int	ft_south_image(t_total *total)
{
	total->img_south = ft_calloc(sizeof(t_image), 1);
	if (total->img_south == 0)
		return (0);
	total->img_south->img = mlx_xpm_file_to_image(total->window->mlx_ptr,
			total->info->south_path, &total->img_south->width,
			&total->img_south->height);
	if (total->img_south->img == 0)
		return (ft_free_images(total, total->img_south, 1));
	total->img_south->img_ptr = mlx_get_data_addr(total->img_south->img,
			&total->img_south->bpp, &total->img_south->line_length,
			&total->img_south->endian);
	if (total->img_south->img_ptr == 0)
		return (ft_free_images(total, total->img_south, 1));
	return (0);
}

int	ft_east_image(t_total *total)
{
	total->img_east = ft_calloc(sizeof(t_image), 1);
	if (total->img_east == 0)
		return (0);
	total->img_east->img = mlx_xpm_file_to_image(total->window->mlx_ptr,
			total->info->east_path, &total->img_east->width,
			&total->img_east->height);
	if (total->img_east->img == 0)
		return (ft_free_images(total, total->img_east, 2));
	total->img_east->img_ptr = mlx_get_data_addr(total->img_east->img,
			&total->img_east->bpp, &total->img_east->line_length,
			&total->img_east->endian);
	if (total->img_east->img_ptr == 0)
		return (ft_free_images(total, total->img_east, 2));
	return (0);
}

int	ft_west_image(t_total *total)
{
	total->img_west = ft_calloc(sizeof(t_image), 1);
	if (total->img_west == 0)
		return (0);
	total->img_west->img = mlx_xpm_file_to_image(total->window->mlx_ptr,
			total->info->west_path, &total->img_west->width,
			&total->img_west->height);
	if (total->img_west->img == 0)
		return (ft_free_images(total, total->img_west, 3));
	total->img_west->img_ptr = mlx_get_data_addr(total->img_west->img,
			&total->img_west->bpp, &total->img_west->line_length,
			&total->img_west->endian);
	if (total->img_west->img_ptr == 0)
		return (ft_free_images(total, total->img_west, 3));
	return (0);
}
