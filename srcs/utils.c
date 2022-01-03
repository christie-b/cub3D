/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:28:45 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/14 17:44:24 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	char	*dst;
	size_t	i;

	total = count * size;
	dst = malloc(total);
	if (dst == 0)
		return (NULL);
	i = 0;
	while (i < total)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}

int	ft_mini_atoi(char *line, int *i)
{
	int	tmp;

	tmp = 0;
	while (line[*i] && line[*i] != ',' && line[*i] != ' ')
	{
		while (line[*i] == '+')
			(*i)++;
		if (line[*i] < '0' || line[*i] > '9')
			return (-1);
		tmp = tmp * 10 + line[*i] - '0';
		(*i)++;
	}
	return (tmp);
}

int	ft_count_commas(char *line, int j)
{
	int	counter;

	counter = 0;
	while (line[j])
	{
		if (line[j] == ',')
			counter++;
		j++;
	}
	return (counter);
}

int	ft_open(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	return (fd);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*dst;

	dst = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		dst[i] = 0;
		i++;
	}
}
