/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:09:31 by opacaud           #+#    #+#             */
/*   Updated: 2022/01/03 08:49:35 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	ft_check_cub(char *av, t_info *info)
{
	int	size;

	size = ft_strlen(av);
	if ((size < 5) || (av[size - 1] != 'b') || (av[size - 2] != 'u')
		|| (av[size - 3] != 'c') || (av[size - 4] != '.'))
		return (ft_write_error("The map must have a .cub extension.\n",
				1, info));// leak with invalid extension
	return (0);
}

void	ft_check_perso(char map, t_info *info, int *perso)
{
	if (map == 'N' || map == 'S' || map == 'W' || map == 'E')
	{
		(*perso)++;
		info->total->player->orientation = map;
	}
}

int	ft_check_empty_lines_original_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (ft_strlen(map[i]) == 0)
			return (1);
		if (map[i][ft_strlen(map[i]) - 1] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_map(char **map, t_info *info, int i)
{
	int	j;
	int	perso;

	perso = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_check_perso(map[i][j], info, &perso);
			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'N'
				|| map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E'
				|| map[i][j] == ' ')
				j++;
			else
				return (ft_write_error("The map should only contain 0, 1, \
N, S, W, E and spaces.\n", 0, NULL));
		}
		i++;
	}
	if (perso != 1)
		return (ft_write_error("There should be one and only one player.\n",
				0, NULL));
	return (0);
}

int	ft_check_original_map(t_info *info)
{
	if (ft_check_empty_lines_original_map(info->original_map,
			info->map_height))
		return (ft_write_error("Map should not contain any \
empty lines or spaces at the end of the line.\n", 0, NULL));
	if (ft_check_boundaries(info, info->original_map))
		return (ft_write_error("Map should be surrounded by 1.\n", 0, NULL));
	if (ft_check_map(info->original_map, info, 0))
		return (1);
	return (0);
}
