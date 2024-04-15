/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constante.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:31:42 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/15 16:52:18 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTE_H
# define CONSTANTE_H

# define TITLE "CUB3D"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef enum e_color_texte
{
	EMPTY_COLOR ,
	ROUGE ,
	VERT ,
	JAUNE ,
	BLEU ,
	MAGENTA ,
	CYAN ,
	BLANC
}	t_color_texte;

typedef enum e_element_map
{
	UNKNOW,
	VOID,
	WALL,
	SPAWN_N,
	SPAWN_S,
	SPAWN_E,
	SPAWN_W,
	FLOOR_E
}	t_element_map;

typedef enum e_cardinal
{
	IDK,
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_cardinal;

typedef enum e_texture
{
	IDK_T,
	NORTH_T,
	SOUTH_T,
	EAST_T,
	WEST_T,
	FLOOR_T,
	CEILING_T
}	t_texture;

typedef enum e_error_code
{
	ERR_NULL,
	ERR_UNKNOW,
	ERR_MALLOC,
	ERR_IS_DIR,
	ERR_OPEN,
	ERR_INVALID_FILE,
	ERR_TO_MUCH_LINE,
	ERR_SAME_TEXTURE,
	ERR_BAD_SYNTAXE_TEXTURE,
	ERR_MISSING_TEXTURE,
	ERR_BAD_SYNTAXE_MAP,
	ERR_WALL_NOT_CLOSE,
	ERR_REDUNDANCE_SPAWN,
	ERR_MISSING_MAP,
	ERR_MISSING_SPAWN,
	ERR_INIT_LIBX,
	ERR_WIN_LIBX,
	ERR_XPM_TO_IMG,
	ERR_TEX,
	ERR_SIZE_MALLOC,
}	t_error_code;

typedef enum e_extension_file
{
	XPM,
	CUB
}	t_extension_file;

#endif