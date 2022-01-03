/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_original_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:08:27 by opacaud           #+#    #+#             */
/*   Updated: 2021/12/20 16:29:54 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	ft_fill_tab_with_map(t_info *info, int fd, char **line, char **tmp)
{
	int	i;

	i = 1;
	while (i < info->map_height)
	{
		get_next_line(fd, line);
		tmp[i] = ft_strdup(*line);
		if (info->map_width < ft_strlen(*line))
			info->map_width = ft_strlen(*line);
		free(*line);
		i++;
	}
	tmp[i] = NULL;
}

char	**ft_create_original(t_info *info)
{
	char	**original;
	int		fd;
	char	*line;

	line = NULL;
	fd = ft_open(info->av);
	if (fd == 0)
		return (0);
	original = ft_calloc(sizeof(char *), (info->map_height + 1));
	if (!original)
		return (0);
	ft_go_to_first_line_map(1, &line, info, fd);
	info->map_width = ft_strlen(line);
	original[0] = ft_strdup(line);
	free(line);
	ft_fill_tab_with_map(info, fd, &line, original);
	close(fd);
	return (original);
}

void	ft_trim_map_height(char **map, t_info *info)
{
	int	size;

	size = info->map_height - 1;
	while (ft_strlen(map[size]) == 0)
	{
		info->map_height--;
		size--;
	}
}

int	ft_get_original_map(int fd, t_info *info)
{
	char	*line;
	int		ret;

	ret = get_next_line(fd, &line);
	while (ret != 0 && ft_strlen(line) == 0)
	{
		free(line);
		ret = get_next_line(fd, &line);
	}
	info->map_height++;
	info->first_line = ft_strdup(line);
	free(line);
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		info->map_height++;
		free(line);
	}
	close(fd);
	if (info->map_height < 3)
		return (ft_write_error("There must be a valid map at the end of the \
file.\n", 0, NULL));
	info->original_map = ft_create_original(info);
	ft_trim_map_height(info->original_map, info);
	return (ft_check_map_height_width(info));
}
