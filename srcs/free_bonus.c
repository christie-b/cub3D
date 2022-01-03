/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:47:28 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/22 10:02:06 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

void	ft_free_map(char **map)
{
	int	i;

	if (map && map[0])
	{
		i = 0;
		while (map[i])
		{
			free(map[i]);
			map[i] = NULL;
			i++;
		}
		free(map);
		map = NULL;
	}
}

void	ft_free_sprite_images(t_total *total)
{
	int	i;

	i = 0;
	while (i < NB_TEXTURES)
	{
		mlx_destroy_image(total->window->mlx_ptr, total->img_textures[i]->img);
		free(total->img_textures[i]);
		total->img_textures[i] = NULL;
		i++;
	}
	free(total->img_textures);
	total->img_textures = NULL;
}

void	ft_free_ray_and_sprite(t_info *info)
{
	int	i;

	i = -1;
	while (++i < WIN_W)
	{
		free(info->total->ray[i]);
		info->total->ray[i] = NULL;
	}
	if (info->total->ray)
	{
		free(info->total->ray);
		info->total->ray = NULL;
	}
	if (info->total->sprite)
	{
		i = 0;
		while (i < info->nb_sprites)
		{
			free(info->total->sprite[i]);
			info->total->sprite[i] = NULL;
			i++;
		}
		free(info->total->sprite);
		info->total->sprite = NULL;
	}
}

int	ft_free(t_info *info)
{
	free(info->north_path);
	info->north_path = NULL;
	free(info->south_path);
	info->south_path = NULL;
	free(info->west_path);
	info->west_path = NULL;
	free(info->east_path);
	info->east_path = NULL;
	free(info->first_line);
	info->first_line = NULL;
	ft_free_map(info->map);
	ft_free_map(info->original_map);
	ft_free_ray_and_sprite(info);
	return (1);
}

int	ft_free_tab(char **tab)
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return (1);
}
