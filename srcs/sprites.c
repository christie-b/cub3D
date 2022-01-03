/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:04:57 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/21 13:26:49 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

void	ft_fill_sprites_info(t_total *total, int *nb_visible_sprites, int i,
t_sprite *visible_sprites)
{
	double	angle_sprite_player;

	while (++i < total->info->nb_sprites)
	{
		angle_sprite_player = total->player->rotation_angle
			- atan2(total->sprite[i]->y - total->player->pos_pix_y,
				total->sprite[i]->x - total->player->pos_pix_x);
		if (angle_sprite_player > PI)
			angle_sprite_player -= 2 * PI;
		if (angle_sprite_player < -PI)
			angle_sprite_player += 2 * PI;
		angle_sprite_player = fabs(angle_sprite_player);
		if (angle_sprite_player < (total->fov_angle / 2) + 0.2)
		{
			total->sprite[i]->visible = 1;
			total->sprite[i]->angle = angle_sprite_player;
			total->sprite[i]->distance = distance_between_points
				(total->sprite[i]->x, total->sprite[i]->y,
					total->player->pos_pix_x, total->player->pos_pix_y);
			visible_sprites[(*nb_visible_sprites)] = *total->sprite[i];
			(*nb_visible_sprites)++;
		}
		else
			total->sprite[i]->visible = 0;
	}
}

void	ft_sort_sprites(int nb_visible_sprites, t_sprite *visible_sprites)
{
	t_sprite	tmp;
	int			i;
	int			j;

	if (nb_visible_sprites > 1)
	{
		i = 0;
		while (i < nb_visible_sprites - 1)
		{
			j = i + 1;
			while (j < nb_visible_sprites)
			{
				if (visible_sprites[i].distance < visible_sprites[j].distance)
				{
					tmp = visible_sprites[i];
					visible_sprites[i] = visible_sprites[j];
					visible_sprites[j] = tmp;
				}
				j++;
			}
			i++;
		}
	}
}

void	ft_get_texture_offset_x(t_total *total, int x, int *texture_offset_x,
int i)
{
	double	texel_width;

	texel_width = (total->img_textures[0]->width / total->sprite[i]->width);
	*texture_offset_x = (x - total->sprite[i]->left_x) * texel_width;
	if (*texture_offset_x < 0)
		*texture_offset_x = 0;
}

void	ft_fill_sprites_variables(t_total *total, int i, double perp_distance,
double distance_proj_plane)
{
	total->sprite[i]->height = (MINI_TILE_SIZE / perp_distance)
		* distance_proj_plane;
	total->sprite[i]->width = total->sprite[i]->height;
	total->sprite[i]->top_y = (WIN_H / 2) - (total->sprite[i]->height / 2);
	if (total->sprite[i]->top_y < 0)
		total->sprite[i]->top_y = 0;
	total->sprite[i]->bottom_y = (WIN_H / 2)
		+ (total->sprite[i]->height / 2);
	if (total->sprite[i]->bottom_y > WIN_H)
		total->sprite[i]->bottom_y = WIN_H;
	total->sprite[i]->sprite_angle = atan2(total->visible_sprites[i].y
			- total->player->pos_pix_y, total->visible_sprites[i].x
			- total->player->pos_pix_x) - total->player->rotation_angle;
	total->sprite[i]->screen_pos_x = tan(total->sprite[i]->sprite_angle)
		* distance_proj_plane;
}
