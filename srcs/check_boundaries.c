/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_boundaries.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:24:38 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/22 11:49:55 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	ft_check_boundaries_first_line(char **tmp)
{
	int	j;

	j = 1;
	if (ft_check_whole_line_for_spaces_ones(tmp[0]))
		return (1);
	if (ft_check_spaces_and_around_first(tmp, 0, &j))
		return (1);
	while (tmp[0][j + 1])
	{
		if (tmp[0][j] == ' ')
		{
			if ((tmp[0][j - 1] != '1' && tmp[0][j - 1] != ' ')
				|| (tmp[0][j + 1] != '1' && tmp[0][j + 1] != ' ')
				|| (tmp[1][j - 1] != '1' && tmp[1][j - 1] != ' ')
				|| (tmp[1][j] != '1' && tmp[1][j] != ' ')
				|| (tmp[1][j + 1] != '1' && tmp[1][j + 1] != ' '))
				return (1);
		}
		if ((tmp[0][j] != ' ' && tmp[0][j] != '1') || (tmp[0][j + 1] != ' '
			&& tmp[0][j + 1] != '1'))
			return (1);
		j++;
	}
	return (0);
}

int	ft_check_boundaries_last_line(char **tmp, t_info *info)
{
	int	max;
	int	j;

	max = info->map_height - 1;
	j = 1;
	if (ft_check_whole_line_for_spaces_ones(tmp[max])
		|| ft_check_spaces_and_around_last(tmp, max, &j))
		return (1);
	while (tmp[max][j + 1])
	{
		if (tmp[max][j] == ' ')
		{
			if ((tmp[max - 1][j - 1] != '1' && tmp[max - 1][j - 1] != ' ')
				|| (tmp[max - 1][j] != '1' && tmp[max - 1][j] != ' ')
				|| (tmp[max - 1][j + 1] != '1' && tmp[max - 1][j + 1] != ' ')
				|| (tmp[max][j - 1] != '1' && tmp[max][j - 1] != ' ')
				|| (tmp[max][j + 1] != '1' && tmp[max][j + 1] != ' '))
				return (1);
		}
		if ((tmp[max][j] != ' ' && tmp[max][j] != '1')
			|| (tmp[max][j + 1] != ' ' && tmp[max][j + 1] != '1'))
			return (1);
		j++;
	}
	return (0);
}

int	ft_check_boundaries_fake_first_line(char *first, char *second)
{
	int	i;

	i = ft_strlen(first);
	while (second[i])
	{
		if (second[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_boundaries_middle_lines(char **tmp, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (++i < info->map_height - 1)
	{
		if (ft_strlen(tmp[i - 1]) < ft_strlen(tmp[i]))
			if (ft_check_boundaries_fake_first_line(tmp[i - 1], tmp[i]))
				return (1);
		if (ft_strlen(tmp[i]) > ft_strlen(tmp[i + 1]))
			if (ft_check_boundaries_fake_first_line(tmp[i + 1], tmp[i]))
				return (1);
		if ((tmp[i][0] != '1' && tmp[i][0] != ' ')
			|| (tmp[i][ft_strlen(tmp[i]) - 1] != '1'))
			return (1);
		if (ft_check_spaces_and_around(tmp, i, &j, 0)
			|| (tmp[i][ft_strlen(tmp[i]) - 1] != '1'
			&& tmp[i][ft_strlen(tmp[i]) - 1] != ' ')
			|| (ft_strlen(tmp[i - 1]) >= ft_strlen(tmp[i])
			&& tmp[i - 1][j] && tmp[i - 1][j] != ' ' && tmp[i - 1][j] != '1')
			|| (ft_strlen(tmp[i + 1]) >= ft_strlen(tmp[i])
			&& tmp[i + 1][j] && tmp[i + 1][j] != ' ' && tmp[i + 1][j] != '1'))
			return (1);
	}
	return (0);
}

int	ft_check_boundaries(t_info *info, char **tmp)
{
	if (ft_check_boundaries_first_line(tmp))
		return (1);
	if (ft_check_boundaries_middle_lines(tmp, info))
		return (1);
	if (ft_check_boundaries_last_line(tmp, info))
		return (1);
	return (0);
}
