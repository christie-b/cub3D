/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:14:30 by opacaud           #+#    #+#             */
/*   Updated: 2021/12/22 10:48:29 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

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

int	ft_free(t_info *info)
{
	int	i;

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
	i = 0;
	while (i < WIN_W)
	{
		free(info->total->ray[i]);
		i++;
	}
	free(info->total->ray);
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

int	ft_free_images(t_total *total, t_image *img, int i)
{
	mlx_destroy_image(total->window->mlx_ptr, total->image->img);
	free(total->image);
	free(img);
	if (i == 1 || i == 2 || i == 3)
	{
		mlx_destroy_image(total->window->mlx_ptr, total->img_north->img);
		free(total->img_north);
	}
	if (i == 2 || i == 3)
	{
		mlx_destroy_image(total->window->mlx_ptr, total->img_south->img);
		free(total->img_south);
	}
	if (i == 3)
	{
		mlx_destroy_image(total->window->mlx_ptr, total->img_east->img);
		free(total->img_east);
	}
	if (total->window->mlx_ptr)
		mlx_destroy_window(total->window->mlx_ptr, total->window->win_ptr);
	mlx_destroy_display(total->window->mlx_ptr);
	free(total->window->mlx_ptr);
	return (1);
}

int	ft_free_null(char **line)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	return (1);
}
