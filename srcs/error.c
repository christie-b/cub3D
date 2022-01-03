/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:13:35 by opacaud           #+#    #+#             */
/*   Updated: 2021/12/07 16:17:31 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	ft_write_error(char *message, int free_map, t_info *info)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	if (free_map == 1 && info)
		ft_free(info);
	return (1);
}
