/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:27:19 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/20 15:27:39 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	ft_mouse_move(int x, int y, t_total *total)
{
	int	default_mouse_x;

	default_mouse_x = WIN_W / 2;
	if (x == default_mouse_x)
		return (0);
	if (x < default_mouse_x)
		total->player->rot_left = 1;
	else
		total->player->rot_right = 1;
	total->player->mouse_moving = 1;
	mlx_mouse_get_pos(total->window->mlx_ptr, total->window->win_ptr, &x, &y);
	return (0);
}
