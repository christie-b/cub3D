/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces_and_around.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:51:24 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/22 12:21:38 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	ft_check_last_char(char *tmp1, char *tmp2)
{
	if (ft_strlen(tmp1) >= ft_strlen(tmp2))
	{
		if (tmp1[ft_strlen(tmp2) - 1] != '1')
			return (1);
	}
	return (0);
}

int	ft_check_spaces_and_around_first(char **tmp, int i, int *j)
{
	int	k;

	k = 0;
	while (tmp[i][k + 1])
	{
		if (tmp[i][k] == ' ')
		{
			if (k == 0 && ((tmp[i][k + 1] != '1' && tmp[i][k + 1] != ' ')
				|| (tmp[i + 1][k] != '1' && tmp[i + 1][k] != ' ')
				|| (tmp[i + 1][k + 1] != '1' && tmp[i + 1][k + 1] != ' ')))
				return (1);
			if (k > 0 && ((tmp[i][k - 1] != '1' && tmp[i][k - 1] != ' ')
				|| (tmp[i][k + 1] != '1' && tmp[i][k + 1] != ' ')
				|| (tmp[i + 1][k - 1] != '1' && tmp[i + 1][k - 1] != ' ')
				|| (tmp[i + 1][k] != '1' && tmp[i + 1][k] != ' ')
				|| (tmp[i + 1][k + 1] != '1' && tmp[i + 1][k + 1] != ' ')))
				return (1);
		}
		k++;
	}
	*j = k;
	if (ft_check_last_char(tmp[i + 1], tmp[i]))
		return (1);
	return (0);
}

int	ft_check_spaces_and_around(char **tmp, int i, int *j, int k)
{
	while (tmp[i][k + 1])
	{
		if (tmp[i][k] == ' ')
		{
			if (k == 0 && ((tmp[i - 1][k] != '1' && tmp[i - 1][k] != ' ')
				|| (tmp[i - 1][k + 1] != '1' && tmp[i - 1][k + 1] != ' ')
				|| (tmp[i][k + 1] != '1' && tmp[i][k + 1] != ' ')
				|| (tmp[i + 1][k] != '1' && tmp[i + 1][k] != ' ')
				|| (tmp[i + 1][k + 1] != '1' && tmp[i + 1][k + 1] != ' ')))
				return (1);
			if (k > 0 && ((tmp[i - 1][k - 1] != '1' && tmp[i - 1][k - 1] != ' ')
				|| (tmp[i - 1][k] != '1' && tmp[i - 1][k] != ' ')
				|| (tmp[i - 1][k + 1] != '1' && tmp[i - 1][k + 1] != ' ')
				|| (tmp[i][k - 1] != '1' && tmp[i][k - 1] != ' ')
				|| (tmp[i][k + 1] != '1' && tmp[i][k + 1] != ' ')
				|| (tmp[i + 1][k - 1] != '1' && tmp[i + 1][k - 1] != ' ')
				|| (tmp[i + 1][k] != '1' && tmp[i + 1][k] != ' ')
				|| (tmp[i + 1][k + 1] != '1' && tmp[i + 1][k + 1] != ' ')))
				return (1);
		}
		k++;
	}
	*j = k;
	return (0);
}

int	ft_check_spaces_and_around_last(char **tmp, int i, int *j)
{
	int	k;

	k = 0;
	while (tmp[i][k + 1])
	{
		if (tmp[i][k] == ' ')
		{
			if (k == 0 && ((tmp[i - 1][k] != '1' && tmp[i - 1][k] != ' ')
				|| (tmp[i - 1][k + 1] != '1' && tmp[i - 1][k + 1] != ' ')
				|| (tmp[i][k + 1] != '1' && tmp[i][k + 1] != ' ')))
				return (1);
			if (k > 0 && ((tmp[i - 1][k - 1] != '1' && tmp[i - 1][k - 1] != ' ')
				|| (tmp[i - 1][k] != '1' && tmp[i - 1][k] != ' ')
				|| (tmp[i - 1][k + 1] != '1' && tmp[i - 1][k + 1] != ' ')
				|| (tmp[i][k - 1] != '1' && tmp[i][k - 1] != ' ')
				|| (tmp[i][k + 1] != '1' && tmp[i][k + 1] != ' ')))
				return (1);
		}
		k++;
	}
	*j = k;
	if (ft_check_last_char(tmp[i - 1], tmp[i]))
		return (1);
	return (0);
}
