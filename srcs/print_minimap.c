/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:27:04 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/22 10:36:50 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

void	ft_cast_rays_bonus(t_total *total)
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
		ft_print_rays(total, total->ray[i]->ray_angle, i);
		ray_angle += total->fov_angle / nb_rays;
		i++;
	}
}

int	ft_print_mini_map(t_total *total)
{
	int	i;
	int	j;

	i = 0;
	while (i < total->info->map_height)
	{
		j = 0;
		while (total->info->original_map[i][j])
		{
			if (total->info->original_map[i][j] == '1')
				ft_print_bloc_mini_wall(total, i * MINI_TILE_SIZE,
					j * MINI_TILE_SIZE, WHITE);
			j++;
		}
		i++;
	}
	ft_cast_rays_bonus(total);
	ft_print_perso(total);
	ft_print_player_dir(total, total->player->rotation_angle, BLUE);
	ft_print_sprite_mini(total);
	return (0);
}
