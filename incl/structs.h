/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <opacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:24:27 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/21 13:36:08 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

struct	s_total;

typedef struct s_info
{
	char			*av;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	int				floor[3];
	int				ceiling[3];
	int				counter;
	int				check_double_path;
	char			**original_map;
	char			**map;
	int				map_width;
	int				map_height;
	char			*first_line;
	int				nb_sprites;
	struct s_total	*total;
}				t_info;

typedef struct s_player
{
	double	dir_x;
	double	dir_y;
	char	orientation;
	int		pos_map_x;
	int		pos_map_y;
	double	pos_pix_x;
	double	pos_pix_y;
	int		mov_up;
	int		mov_down;
	int		mov_left;
	int		mov_right;
	int		rot_left;
	int		rot_right;
	int		turn_direction;
	int		axis_direction;
	int		lat_direction;
	double	rotation_angle;
	double	move_speed;
	double	rotation_speed;
	int		mouse_moving;
}				t_player;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_window;

typedef struct s_image
{
	char	*img_ptr;
	void	*img;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_ray
{
	double	ray_angle;
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
	int		ray_facing_down;
	int		ray_facing_right;
	int		found_hor_wall_hit;
	int		found_vert_wall_hit;
	double	hor_wall_hit_x;
	double	hor_wall_hit_y;
	double	vert_wall_hit_x;
	double	vert_wall_hit_y;
	int		was_hit_vert;
	double	x_intercept;
	double	y_intercept;
	double	x_step;
	double	y_step;
	double	ray_length;
}				t_ray;

typedef struct s_wall
{
	double	x;
	double	y;
	double	height;
}				t_wall;

typedef struct s_sprite
{
	double	x;
	double	y;
	double	distance;
	double	angle;
	int		visible;
	double	height;
	double	width;
	double	sprite_angle;
	double	top_y;
	double	bottom_y;
	double	left_x;
	double	right_x;
	double	screen_pos_x;
}				t_sprite;

typedef struct s_total
{
	t_info		*info;
	t_window	*window;
	t_image		*image;
	t_image		*img_north;
	t_image		*img_south;
	t_image		*img_east;
	t_image		*img_west;
	t_image		**img_textures;
	t_player	*player;
	t_ray		**ray;
	t_wall		*wall;
	t_sprite	**sprite;
	double		fov_angle;
	t_sprite	*visible_sprites;
}				t_total;

#endif