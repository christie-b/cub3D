/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 09:43:45 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/22 10:02:35 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

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
	return (0);
}
