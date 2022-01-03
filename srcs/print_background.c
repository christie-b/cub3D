/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:07:55 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/22 10:37:38 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	ft_print_bloc_mini_wall(t_total *total, int i, int j, int color)
{
	int	k;
	int	l;

	k = 0;
	while (k < MINI_TILE_SIZE)
	{
		l = 0;
		while (l < MINI_TILE_SIZE)
		{
			if ((k == 0 || k == MINI_TILE_SIZE - 1 || l == 0
					|| l == MINI_TILE_SIZE - 1))
				my_mlx_pixel_put(total->image, j + l, i + k, DARK_BLUE);
			else
				my_mlx_pixel_put(total->image, j + l, i + k, color);
			l++;
		}
		k++;
	}
}

void	ft_print_sprite_mini(t_total *total)
{
	int	i;
	int	j;

	i = 0;
	while (i < total->info->map_height)
	{
		j = 0;
		while (total->info->original_map[i][j])
		{
			if (total->info->original_map[i][j] == '2')
				ft_print_bloc_mini_perso(total, i * MINI_TILE_SIZE,
					j * MINI_TILE_SIZE, 0x26afd1);
			j++;
		}
		i++;
	}
}

void	ft_print_ceil_and_floor(t_total *total)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIN_H / 2)
	{
		j = -1;
		while (++j < WIN_W)
		{
			my_mlx_pixel_put(total->image, j, i,
				create_trgb(0, total->info->ceiling[0],
					total->info->ceiling[1], total->info->ceiling[2]));
		}
	}
	while (i < WIN_H)
	{
		j = -1;
		while (++j < WIN_W)
		{
			my_mlx_pixel_put(total->image, j, i,
				create_trgb(0, total->info->floor[0], total->info->floor[1],
					total->info->floor[2]));
		}
		i++;
	}
}
