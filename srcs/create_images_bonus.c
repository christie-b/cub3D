/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:48:52 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/22 10:47:16 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

char	*ft_get_sprite_path(int i)
{
	if (i == 0)
		return ("./textures/sprites/0.xpm");
	if (i == 1)
		return ("./textures/sprites/1.xpm");
	if (i == 2)
		return ("./textures/sprites/2.xpm");
	if (i == 3)
		return ("./textures/sprites/3.xpm");
	if (i == 4)
		return ("./textures/sprites/4.xpm");
	if (i == 5)
		return ("./textures/sprites/5.xpm");
	if (i == 6)
		return ("./textures/sprites/6.xpm");
	if (i == 7)
		return ("./textures/sprites/7.xpm");
	if (i == 8)
		return ("./textures/sprites/8.xpm");
	return (0);
}

int	ft_texture_images(t_total *total)
{
	int	i;

	total->img_textures = malloc(sizeof(t_image *) * NB_TEXTURES);
	if (!total->img_textures)
		return (0);
	i = 0;
	while (i < NB_TEXTURES)
	{
		total->img_textures[i] = malloc(sizeof(t_image));
		if (!total->img_textures[i])
			return (0);
		total->img_textures[i]->img = mlx_xpm_file_to_image
			(total->window->mlx_ptr,
				ft_get_sprite_path(i), &total->img_textures[i]->width,
				&total->img_textures[i]->height);
		total->img_textures[i]->img_ptr = mlx_get_data_addr
			(total->img_textures[i]->img,
				&total->img_textures[i]->bpp,
				&total->img_textures[i]->line_length,
				&total->img_textures[i]->endian);
		if (total->img_textures[i]->img_ptr == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_images(t_total *total)
{
	total->image = malloc(sizeof(t_image));
	if (total->image == 0)
		return (0);
	total->image->img = mlx_new_image(total->window->mlx_ptr, WIN_W, WIN_H);
	total->image->img_ptr = mlx_get_data_addr(total->image->img,
			&total->image->bpp, &total->image->line_length,
			&total->image->endian);
	if (total->image->img_ptr == 0)
		return (1);
	if (ft_north_image(total) == 1)
		return (1);
	if (ft_south_image(total) == 1)
		return (1);
	if (ft_east_image(total) == 1)
		return (1);
	if (ft_west_image(total) == 1)
		return (1);
	if (ft_texture_images(total) == 1)
		return (1);
	return (0);
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
