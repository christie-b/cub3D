/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:49:40 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/20 15:50:15 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	ft_check_empty_floor_ceiling(t_info *info, char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
		if (info->floor[0] == -1 || info->floor[1] == -1
			|| info->floor[2] == -1)
			return (1);
	if (ft_strncmp(line, "C ", 2) == 0)
		if (info->ceiling[0] == -1 || info->ceiling[1] == -1
			|| info->ceiling[2] == -1)
			return (1);
	return (0);
}

int	ft_is_all_one(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}
