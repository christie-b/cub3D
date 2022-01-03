# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 09:08:45 by cboutier          #+#    #+#              #
#    Updated: 2021/12/22 13:42:56 by cboutier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	= srcs

NAMES		= main.c \
			parse_info.c check.c \
			get_original_map.c get_map.c \
			check_boundaries.c check2.c \
			error.c free.c utils.c math_utils.c \
			get_next_line.c get_next_line_utils.c \
			mlx.c image_color_utils.c create_images.c create_wall_images.c \
			hooks.c check_spaces_and_around.c \
			print_background.c print_perso.c \
			cast_rays.c intersection.c \
			render_3d_proj.c parsing_utils.c map_utils.c \

BONUS_NAMES	= main_bonus.c \
			parse_info.c check_bonus.c \
			get_original_map.c get_map.c \
			check_boundaries.c check2.c check_spaces_and_around.c \
			error.c free_bonus.c utils.c math_utils.c \
			get_next_line.c get_next_line_utils.c \
			mlx_bonus.c image_color_utils.c create_images_bonus.c \
			create_wall_images.c hooks.c \
			print_background.c print_perso.c \
			cast_rays.c intersection.c \
			render_3d_proj.c sprites.c mouse.c \
			render_sprites.c parsing_utils.c map_utils.c print_minimap.c \

SRCS		= $(addprefix $(SRCS_DIR)/, $(NAMES))

BONUS_SRCS	= $(addprefix $(SRCS_DIR)/, $(BONUS_NAMES))

INCLUDES	= -Iincl

HEADER		= incl/cub3d.h incl/structs.h incl/defines.h

OBJS		= ${SRCS:.c=.o}
OBJS_BONUS	= ${BONUS_SRCS:.c=.o}

DEP			= ${OBJS:.o=.d}
DEP_BONUS	= ${OBJS_BONUS:.o=.d}

NAME		= cub3D

BONUS		= cub3D_bonus

CC			= clang
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

all:		${NAME}
bonus:		${BONUS}

MLX_DIR		= ./mlx_linux
MLX_FLAGS	= -lX11 -lXext -lm -lz

-include ${DEP}

${NAME}:	${OBJS} ${HEADER}
			${CC} ${CFLAGS} ${OBJS} ${INCLUDES} -L${MLX_DIR} -lmlx ${MLX_FLAGS} -o ${NAME}

${BONUS}:	${OBJS_BONUS} ${HEADER}
			${CC} ${CFLAGS} ${OBJS_BONUS} ${INCLUDES} -L${MLX_DIR} -lmlx ${MLX_FLAGS} -o ${BONUS}

.c.o:
			$(CC) -MMD $(CFLAGS) ${INCLUDES} -c $< -o $(<:.c=.o)

clean:
			${RM} ${OBJS} ${OBJS_BONUS} ${DEP} ${DEP_BONUS}

fclean:		clean
			${RM} ${NAME} ${BONUS}

re:			fclean all

.PHONY:		all clean fclean bonus
