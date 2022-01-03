/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:08:53 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/22 09:48:36 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

void	ft_draw_sprites(t_total *total, int x, int i, int j)
{
	int		y;
	int		texture_offset_x;
	int		texture_offset_y;
	int		dist_from_top;
	int		color;

	ft_get_texture_offset_x(total, x, &texture_offset_x, i);
	y = total->sprite[i]->top_y;
	while (y < total->sprite[i]->bottom_y)
	{
		if (x > 0 && x < WIN_W && y > 0 && y < WIN_H)
		{
			dist_from_top = y + (total->sprite[i]->height / 2) - (WIN_H / 2);
			texture_offset_y = dist_from_top
				* (total->img_textures[j]->height / total->sprite[i]->height);
			if (total->visible_sprites[i].distance < total->ray[x]->distance)
			{
				color = get_pixel_color(total->img_textures[j],
						texture_offset_x, texture_offset_y);
				if (color && (color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(total->image, x, y, color);
			}
		}
		y++;
	}
}

void	ft_print_sprites(int nb_visible_sprites, t_sprite *visible_sprites,
t_total *total, double distance_proj_plane)
{
	double			perp_distance;
	int				x;
	int				i;
	static float	j = 0;

	i = -1;
	while (++i < nb_visible_sprites)
	{
		if (j >= NB_TEXTURES)
			j = 0;
		perp_distance = visible_sprites[i].distance
			* cos(visible_sprites[i].angle);
		ft_fill_sprites_variables(total, i, perp_distance, distance_proj_plane);
		total->sprite[i]->left_x = (WIN_W / 2) - (total->sprite[i]->width / 2)
			+ total->sprite[i]->screen_pos_x;
		total->sprite[i]->right_x = total->sprite[i]->left_x
			+ total->sprite[i]->width;
		x = total->sprite[i]->left_x;
		while (x++ < total->sprite[i]->right_x)
			ft_draw_sprites(total, x, i, j);
	}
	j += 0.5;
}

int	ft_render_sprites_proj(t_total *total)
{
	int			nb_visible_sprites;
	double		distance_proj_plane;

	total->visible_sprites = malloc(sizeof(t_sprite) * total->info->nb_sprites);
	if (!total->visible_sprites)
		return (0);
	distance_proj_plane = (WIN_W / 2) / tan(total->fov_angle / 2);
	nb_visible_sprites = 0;
	ft_fill_sprites_info(total, &nb_visible_sprites, -1,
		total->visible_sprites);
	ft_sort_sprites(nb_visible_sprites, total->visible_sprites);
	ft_print_sprites(nb_visible_sprites, total->visible_sprites, total,
		distance_proj_plane);
	free(total->visible_sprites);
	return (0);
}
