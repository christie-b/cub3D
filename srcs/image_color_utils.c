/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_color_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:48:05 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/21 13:27:59 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x < WIN_W && y < WIN_H)
	{
		dst = image->img_ptr + (y * image->line_length + x * (image->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

unsigned int	get_pixel_color(t_image *image, int x, int y)
{
	char	*dst;

	if (x < WIN_W - TILE_SIZE && y < WIN_H - TILE_SIZE)
	{
		dst = image->img_ptr + (x * (image->bpp / 8) + y * image->line_length);
		return ((*(unsigned int *)dst));
	}
	return (0);
}
