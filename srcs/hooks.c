/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:30:39 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/17 12:01:08 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	ft_key_pressed(int keycode, t_total *total)
{
	if (keycode == ESC)
		ft_close_window(total);
	else if (keycode == A_KEY)
		total->player->mov_left = 1;
	else if (keycode == D_KEY)
		total->player->mov_right = 1;
	else if (keycode == W_KEY || keycode == UP_ARR)
		total->player->mov_up = 1;
	else if (keycode == S_KEY || keycode == DWN_ARR)
		total->player->mov_down = 1;
	else if (keycode == LEFT_ARR)
		total->player->rot_left = 1;
	else if (keycode == RIGHT_ARR)
		total->player->rot_right = 1;
	return (0);
}

int	ft_key_released(int keycode, t_total *total)
{
	if (keycode == A_KEY)
		total->player->mov_left = 0;
	else if (keycode == D_KEY)
		total->player->mov_right = 0;
	else if (keycode == W_KEY || keycode == UP_ARR)
		total->player->mov_up = 0;
	else if (keycode == S_KEY || keycode == DWN_ARR)
		total->player->mov_down = 0;
	else if (keycode == LEFT_ARR)
		total->player->rot_left = 0;
	else if (keycode == RIGHT_ARR)
		total->player->rot_right = 0;
	return (0);
}
