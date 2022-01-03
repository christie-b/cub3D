/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:03:42 by opacaud           #+#    #+#             */
/*   Updated: 2021/12/07 09:06:20 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	get_next_line(int fd, char **line)
{
	int		ret;
	char	buf[2];
	char	*tmp;

	*line = ft_strdup("");
	ret = 1;
	while ((ret > 0))
	{
		ret = read(fd, buf, 1);
		buf[ret] = '\0';
		if (buf[0] != '\n')
		{
			tmp = *line;
			*line = ft_strjoin(*line, buf);
			free(tmp);
			tmp = 0;
		}
		else
			break ;
	}
	if (ret > 0)
		return (1);
	else
		return (0);
}
