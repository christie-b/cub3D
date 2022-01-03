/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:08:53 by cboutier          #+#    #+#             */
/*   Updated: 2021/12/23 09:50:52 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "structs.h"
# include "defines.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <strings.h>

/* GNL */

int				get_next_line(int fd, char **line);

/* GNL_UTILS */

int				ft_strlen(char *s);
char			*ft_strdup(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_strjoin(char *s1, char *s2);

/* PARSE_INFO */

int				ft_get_path(t_info *info, char **path, char *line);
int				ft_get_color(t_info *info, char *line);
int				ft_get_first_info(t_info *info, char *line);
int				ft_get_info(int fd, t_info *info, int ret);

/* GET_ORIGINAL_MAP */

void			ft_fill_tab_with_map(t_info *info, int fd, char **line,
					char **tmp);
char			**ft_create_original(t_info *info);
void			ft_trim_map_height(char **map, t_info *info);
int				ft_get_original_map(int fd, t_info *info);

/* MAP_UTILS */
int				ft_go_to_first_line_map(int ret, char **line, t_info *info,
					int fd);
int				ft_check_map_height_width(t_info *info);
int				ft_check_whole_line_for_spaces_ones(char *line);

/* CHECK */

int				ft_check_cub(char *av, t_info *info);
void			ft_check_perso(char map, t_info *info, int *perso);
int				ft_check_empty_lines_original_map(char **map, int height);
int				ft_check_map(char **map, t_info *info, int i);
int				ft_check_original_map(t_info *info);

/* CHECK2 */

int				ft_check_xpm(char *path);
int				ft_check_ceil_and_floor(t_info *info);
int				ft_check_number_of_info(t_info *info);

/* CHECK_SPACES_AND_AROUND */

int				ft_check_last_char(char *tmp1, char *tmp2);
int				ft_check_spaces_and_around_first(char **tmp, int i, int *j);
int				ft_check_spaces_and_around(char **tmp, int i, int *j, int k);
int				ft_check_spaces_and_around_last(char **tmp, int i, int *j);

/* CHECK_BOUNDARIES */

int				ft_check_boundaries_first_line(char **tmp);
int				ft_check_boundaries_last_line(char **tmp, t_info *info);
int				ft_check_boundaries_fake_first_line(char *first, char *second);
int				ft_check_boundaries_middle_lines(char **tmp, t_info *info);
int				ft_check_boundaries(t_info *info, char **tmp);

/* GET_MAP */

int				ft_clean_map(t_info *info);
void			ft_replace_perso_char(t_info *info, int *i, int *j, int *k);
void			ft_replace_values_in_map(t_info *info);

/* RAYS */

void			ft_print_rays(t_total *total, double ray_angle, int i);
void			ft_cast_rays(t_total *total);
int				has_wall(double x, double y, t_total *total);
void			ft_calculate_distance(t_total *total, int i);

/* INTERSECTION */

void			ft_next_hor_touch(t_total *total, int i);
void			ft_horizontal_intercept(t_total *total, int i);
void			ft_next_vert_touch(t_total *total, int i);
void			ft_vertical_intercept(t_total *total, int i);
void			ft_store_smallest_dist(t_total *total, double hor_hit_distance,
					double vert_hit_distance, int i);

/* RENDER_3D_WALL */

void			ft_render_3d_proj_walls(t_total *total);
void			ft_draw_wall(t_total *total, int x, t_image *texture);

/* MATH_UTILS */

double			ft_normalize_angle(double angle);
double			distance_between_points(double x1, double y1, double x2,
					double y2);
double			ft_get_adjustment(int facing);

/* ERROR */

int				ft_write_error(char *message, int free_map, t_info *info);

/* FREE */

void			ft_free_map(char **map);
int				ft_free(t_info *info);
int				ft_free_tab(char **tab);
int				ft_free_images(t_total *total, t_image *img, int i);
int				ft_free_null(char **line);

/* UTILS */

void			*ft_calloc(size_t count, size_t size);
int				ft_mini_atoi(char *line, int *i);
int				ft_count_commas(char *line, int j);
int				ft_open(char *av);
void			ft_bzero(void *s, size_t n);

/* PARSING_UTILS */

int				ft_check_empty_floor_ceiling(t_info *info, char *line);
int				ft_is_all_one(char *line);

/* PRINT_BACKGROUND*/

void			ft_print_bloc_mini_wall(t_total *total, int i, int j,
					int color);
void			ft_print_ceil_and_floor(t_total *total);

/* PRINT_PERSO */

void			ft_print_bloc_mini_perso(t_total *total, int i, int j,
					int color);
void			ft_print_player_dir(t_total *total, double ray_angle,
					int color);
void			ft_print_perso(t_total *total);

/* IMAGE_COLOR_UTILS */

int				create_trgb(int t, int r, int g, int b);
void			my_mlx_pixel_put(t_image *image, int x, int y, int color);
unsigned int	get_pixel_color(t_image *image, int x, int y);

/* MLX */

int				ft_mlx(t_total *total);
int				ft_create_window(t_window *window, char *title);
int				ft_close_window(t_total *total);
int				ft_print_mini_map(t_total *total);

/* HOOKS */

int				ft_key_pressed(int keycode, t_total *total);
int				ft_key_released(int keycode, t_total *total);
void			ft_update_new_pos(t_total *total, double axis_step,
					double lat_step);
void			ft_update_player_pos(t_total *total);

/* MAIN */

int				ft_initialiser_info(char **av, t_total *total);
int				ft_handle_map(char **av, t_info *info, t_total *total);

/* CREATE_WALL_IMAGES */

int				ft_north_image(t_total *total);
int				ft_south_image(t_total *total);
int				ft_east_image(t_total *total);
int				ft_west_image(t_total *total);
int				ft_images(t_total *total);

#endif
