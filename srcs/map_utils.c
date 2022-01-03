/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:29:38 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/22 11:42:11 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	ft_go_to_first_line_map(int ret, char **line, t_info *info, int fd)
{
	while (ret > 0 && ft_strcmp(*line, info->first_line) != 0)
	{
		free(*line);
		ret = get_next_line(fd, line);
	}
	return (ret);
}

int	ft_check_map_height_width(t_info *info)
{
	if (info->map_height > WIN_H / MINI_TILE_SIZE
		|| info->map_width > WIN_W / MINI_TILE_SIZE)
		return (ft_write_error("There must be a valid map at the end of the \
file.\n", 0, NULL));
	return (0);
}

int	ft_check_whole_line_for_spaces_ones(char *line)
{
	int	k;

	k = 0;
	while (line[k])
	{
		if (line[k] != ' ' && line[k] != '1')
			return (1);
		k++;
	}
	return (0);
}
