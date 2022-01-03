/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:27:56 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/22 13:43:06 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

void	ft_initialiser_ceil_and_floor(t_total *total)
{
	total->window->mlx_ptr = 0;
	total->window->win_ptr = 0;
	total->info->total = total;
	total->info->floor[0] = -1;
	total->info->floor[1] = -1;
	total->info->floor[2] = -1;
	total->info->ceiling[0] = -1;
	total->info->ceiling[1] = -1;
	total->info->ceiling[2] = -1;
}

int	ft_initialiser_info(char **av, t_total *total)
{
	int	i;

	ft_bzero(total->info, sizeof(t_info));
	total->info->av = av[1];
	ft_initialiser_ceil_and_floor(total);
	ft_bzero(total->player, sizeof(t_player));
	total->player->move_speed = 1.8;
	total->player->rotation_speed = 1.8 * (PI / 180);
	total->ray = ft_calloc(sizeof(t_ray *), WIN_W + 1);
	if (!total->ray)
		return (1);
	i = 0;
	while (i < WIN_W)
	{
		total->ray[i] = ft_calloc(sizeof(t_ray), 1);
		if (total->ray[i] == 0)
			return (1);
		i++;
	}
	ft_bzero(total->wall, sizeof(t_wall));
	total->fov_angle = 60 * (PI / 180);
	total->sprite = NULL;
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

int	ft_handle_map(char **av, t_info *info, t_total *total)
{
	int	fd;
	int	i;

	if (ft_initialiser_info(av, total))
		return (1);
	if (ft_check_cub(av[1]) == 1)
		return (1);
	fd = ft_open(av[1]);
	if (fd == 0)
		return (ft_write_error("Open failed.\n", 1, info));
	if (ft_get_info(fd, info, 1) || ft_check_original_map(info))
		return (ft_free(info));
	total->sprite = ft_calloc(sizeof(t_sprite *), total->info->nb_sprites);
	if (!total->sprite)
		return (0);
	i = -1;
	while (++i < total->info->nb_sprites)
	{
		total->sprite[i] = ft_calloc(sizeof(t_sprite), 1);
		if (total->sprite[i] == 0)
			return (0);
	}
	ft_clean_map(info);
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	t_total		total;
	t_info		info;
	t_window	window;
	t_player	player;
	t_wall		wall;

	if (ac != 2)
		return (ft_write_error("Usage: ./cub3d ./path_to_map\n", 0, NULL));
	total.info = &info;
	total.window = &window;
	total.player = &player;
	total.wall = &wall;
	if (ft_handle_map(av, total.info, &total))
		return (0);
	if (ft_create_window(total.window, "Cub3D") == 1)
		return (ft_write_error("Could not create window.\n", 1, &info));
	if (ft_images(&total) == 1)
		return (ft_write_error("xpm file is not valid.\n", 1, &info));
	mlx_hook(total.window->win_ptr, 2, 1L << 0, ft_key_pressed, &total);
	mlx_hook(total.window->win_ptr, 3, 1L << 1, ft_key_released, &total);
	mlx_hook(total.window->win_ptr, 17, 0, ft_close_window, &total);
	mlx_hook(total.window->win_ptr, 06, 1L << 6, ft_mouse_move, &total);
	mlx_loop_hook(total.window->mlx_ptr, ft_mlx, &total);
	mlx_loop(total.window->mlx_ptr);
	ft_free(total.info);
}
