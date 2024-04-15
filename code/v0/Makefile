# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 17:05:40 by yzaoui            #+#    #+#              #
#    Updated: 2024/04/15 15:29:02 by lazanett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean bonus

############### OBJ de CUB3D

ERROR_PATH  =	error/
ERROR_FILES =	error_program.c

PARSING_PATH  =	parsing/
PARSING_FILES =	check_file.c					\
				orientation_texture_parsing.c	\
				rgb_texture_parsing.c			\

SHOW_STRUCT_PATH  =	show_struct/
SHOW_STRUCT_FILES =	color.c			\
					show_all.c		\
					show_files.c	\
					show_texture.c	\
					show_world.c

STRUCT_PATH  =	struct/
STRUCT_FILES =	init_free_all_texture.c	\
				init_free_all.c			\
				init_free_cellule.c		\
				init_free_file_cub.c	\
				init_free_world.c		\
				init_free_minilibx.c	\
				init_free_data_file.c	\
				init_free_img.c			\
				init_free_color.c		\
				init_free_tex.c			\

UTILS_PATH  =	utils/
UTILS_FILES =	ft_calloc.c	\
				ft_split.c	\
				gnl.c		\
				gnl_utils.c	\
				utils1.c	\
				utils2.c	\
				utils3.c	\
				verif_element.c

EXEC_PATH  =	executing/
EXEC_FILES =	start_exec.c	\
				key.c	\
				move.c	\
				init_orientation.c	\
				conv_texture.c	\
				raycasting.c	\
				raycasting_utils.c	\
				texture.c	\
				vision.c	\
				wall.c	\

CUB3D_PATH = Source/
CUB3D_FILES =	main.c													\
				${addprefix ${UTILS_PATH}, ${UTILS_FILES}}				\
				${addprefix ${STRUCT_PATH}, ${STRUCT_FILES}}			\
				${addprefix ${SHOW_STRUCT_PATH}, ${SHOW_STRUCT_FILES}}	\
				${addprefix ${PARSING_PATH}, ${PARSING_FILES}}			\
				${addprefix ${ERROR_PATH}, ${ERROR_FILES}}				\
				${addprefix ${EXEC_PATH}, ${EXEC_FILES}}				\

OBJ_PATH  = obj/
CUB3D_OBJ = ${addprefix ${OBJ_PATH}, ${CUB3D_FILES:.c=.o}}

############### ligne de commande

MLX_FLAGS	=	-lmlx -lXext -lX11 -lm
MLX_LIB		=	-I ./Library/minilibx-linux -L ./Library/minilibx-linux
MAKE_MLX	=	@make -s -C ./Library/minilibx-linux

HEADER = ./Header

RM = @rm -f -rf
CC = cc
C_FLAGS = -g3 -Wall -Wextra -Werror

PROGRAM_NAME = cub3D

############### COMMANDE OBLIGATOIRE

all: $(OBJ_PATH) ${PROGRAM_NAME}

${PROGRAM_NAME}: ${CUB3D_OBJ}
	${MAKE_MLX}
	@$(CC) $(C_FLAGS) ${MLX_LIB} ${CUB3D_OBJ} ${MLX_FLAGS} -o ${PROGRAM_NAME}

$(OBJ_PATH)%.o: $(CUB3D_PATH)%.c
	@mkdir -p $(@D)
	@$(CC) $(C_FLAGS) -I /usr/include -I mlx_linux -O3 -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	${MAKE_MLX} clean
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) ${PROGRAM_NAME}

norme:
	clear
	@ if ! norminette ./Source | grep "Error"; then echo "\033[32mOK!\033[0m"; fi

re: fclean all
