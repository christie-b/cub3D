/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:39:01 by opacaud           #+#    #+#             */
/*   Updated: 2021/12/22 11:51:31 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	ft_check_xpm(char *path)
{
	int	size;
	int	fd;

	fd = open(path, O_RDONLY);
	size = ft_strlen(path);
	if ((size < 5) || (path[size - 1] != 'm') || (path[size - 2] != 'p')
		|| (path[size - 3] != 'x') || (path[size - 4] != '.'))
		return (ft_write_error("The textures must be xpm files.\n",
				0, NULL));
	if (fd < 0)
		return (ft_write_error("xpm file does not exist.\n",
				0, NULL));
	close(fd);
	return (0);
}

int	ft_check_ceil_and_floor(t_info *info)
{
	if (info->floor[0] == -1 || info->floor[1] == -1 || info->floor[2] == -1
		|| info->ceiling[0] == -1 || info->ceiling[1] == -1
		|| info->ceiling[2] == -1)
		return (1);
	return (0);
}

int	ft_all_is_filled(t_info *info)
{
	if (info->ceiling[0] == -1 || info->ceiling[1] == -1
		|| info->ceiling[2] == -1 || info->floor[0] == -1
		|| info->floor[1] == -1 || info->floor[2] == -1
		|| !info->north_path || !info->west_path
		|| !info->south_path || !info->east_path)
		return (0);
	return (1);
}

int	ft_check_number_of_info(t_info *info)
{
	if (ft_all_is_filled(info) == 0)
		return (ft_write_error("Map should contain the right amount of info \
about textures and colors and a valid map.\n", 0, NULL));
	if (ft_check_ceil_and_floor(info))
		return (ft_write_error("There should only be one line about ceiling color \
and one line about floor color.\n", 0, NULL));
	if (info->counter != 6 || ft_all_is_filled(info) == 0)
		return (ft_write_error("Map should contain the right amount of info \
about textures and colors.\n", 0, NULL));
	return (0);
}
