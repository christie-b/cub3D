/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:10:08 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/22 12:15:27 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

int	ft_check_cub(char *av)
{
	int	size;

	size = ft_strlen(av);
	if ((size < 5) || (av[size - 1] != 'b') || (av[size - 2] != 'u')
		|| (av[size - 3] != 'c') || (av[size - 4] != '.'))
		return (ft_write_error("The map must have a .cub extension.\n",
				0, NULL));
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

int	ft_is_acceptable_char(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == ' ')
		return (1);
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
			if (ft_is_acceptable_char(map[i][j]))
			{
				if (map[i][j] == '2')
					info->nb_sprites++;
				j++;
			}
			else
				return (ft_write_error("The map should only contain 0, 1, 2, \
N, S, W, E and spaces.\n", 0, NULL));
		}
		i++;
	}
	if (perso != 1)
		return (ft_write_error("There should be one and only one player.\n",
				0, NULL));
	return (0);
}
