/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_perso.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:51:26 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/17 18:07:08 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	ft_print_bloc_mini_perso(t_total *total, int i, int j, int color)
{
	int	k;
	int	l;

	k = MINI_TILE_SIZE / 5;
	while (k < MINI_TILE_SIZE - (MINI_TILE_SIZE / 5))
	{
		l = MINI_TILE_SIZE / 5;
		while (l < MINI_TILE_SIZE - MINI_TILE_SIZE / 5)
		{
			my_mlx_pixel_put(total->image, j + l, i + k, color);
			l++;
		}
		k++;
	}
}

void	ft_print_player_dir(t_total *total, double ray_angle, int color)
{
	int	i;

	i = 0;
	if ((total->player->pos_pix_x > 0 && total->player->pos_pix_x < WIN_W)
		&& (total->player->pos_pix_y > 0 && total->player->pos_pix_y < WIN_H))
	{
		while (i < 30)
		{
			if ((total->player->pos_pix_x + (cos(ray_angle) * (30 - i)))
				> MINI_TILE_SIZE
				&& (total->player->pos_pix_y + (sin(ray_angle) * (30 - i)))
				> MINI_TILE_SIZE)
			{
				my_mlx_pixel_put(total->image,
					total->player->pos_pix_x + (cos(ray_angle) * (30 - i)),
					total->player->pos_pix_y + (sin(ray_angle) * (30 - i)),
					color);
			}
			i++;
		}
	}
}

void	ft_print_perso(t_total *total)
{
	int	i;
	int	j;

	i = 0;
	while (i < total->info->map_height)
	{
		j = 0;
		while (total->info->original_map[i][j])
		{
			if (total->info->original_map[i][j] == 'N'
				|| total->info->original_map[i][j] == 'S'
				|| total->info->original_map[i][j] == 'W'
				|| total->info->original_map[i][j] == 'E')
				ft_print_bloc_mini_perso(total, total->player->pos_pix_y
					- (0.5 * MINI_TILE_SIZE), total->player->pos_pix_x
					- (0.5 * MINI_TILE_SIZE), BLUE);
			j++;
		}
		i++;
	}
}
