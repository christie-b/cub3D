/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:51:19 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/21 10:57:32 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	ft_get_dir(char direction, t_total *total)
{
	if (direction == 'N')
	{
		total->player->dir_x = 0;
		total->player->dir_y = -1;
		total->player->rotation_angle = PI / 2 * 3;
	}
	else if (direction == 'S')
	{
		total->player->dir_x = 0;
		total->player->dir_y = 1;
		total->player->rotation_angle = PI / 2;
	}
	else if (direction == 'W')
	{
		total->player->dir_x = -1;
		total->player->dir_y = 0;
		total->player->rotation_angle = PI;
	}
	else if (direction == 'E')
	{
		total->player->dir_x = 1;
		total->player->dir_y = 0;
		total->player->rotation_angle = 0;
	}
}

void	ft_replace_perso_char(t_info *info, int *i, int *j, int *k)
{
	*j = -1;
	while (info->original_map[*i][++(*j)])
	{
		if (info->original_map[*i][*j] == ' ')
			info->map[*i][*j] = '1';
		else
			info->map[*i][*j] = info->original_map[*i][*j];
		if (info->original_map[*i][*j] == 'N'
			|| info->original_map[*i][*j] == 'S'
			|| info->original_map[*i][*j] == 'W'
			|| info->original_map[*i][*j] == 'E')
		{
			ft_get_dir(info->original_map[*i][*j], info->total);
			info->map[*i][*j] = '0';
			info->total->player->pos_map_x = *j + 0.5;
			info->total->player->pos_map_y = *i + 0.5;
			info->total->player->pos_pix_x = (*j + 0.5) * MINI_TILE_SIZE;
			info->total->player->pos_pix_y = (*i + 0.5) * MINI_TILE_SIZE;
		}
		if (info->original_map[*i][*j] == '2')
		{
			info->total->sprite[*k]->x = (*j + 0.5) * MINI_TILE_SIZE;
			info->total->sprite[(*k)++]->y = (*i + 0.5) * MINI_TILE_SIZE;
		}
	}
}

void	ft_replace_values_in_map(t_info *info)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < info->map_height)
	{
		ft_replace_perso_char(info, &i, &j, &k);
		if (j < info->map_width - 1)
		{
			while (j < info->map_width)
			{
				info->map[i][j] = '1';
				j++;
			}
		}
		info->map[i][j] = '\0';
		i++;
	}
	info->map[i] = NULL;
}

int	ft_clean_map(t_info *info)
{
	int	i;

	info->map = malloc(sizeof(char *) * (info->map_height + 1));
	if (!info->map)
		return (0);
	i = 0;
	while (i < info->map_height)
	{
		info->map[i] = ft_calloc(sizeof(char), (info->map_width + 1));
		if (!info->map[i])
			return (0);
		i++;
	}
	ft_replace_values_in_map(info);
	return (0);
}
