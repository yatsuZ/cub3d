/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:48:13 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/19 16:00:21 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

# include "./import.h"

typedef struct s_xy
{
	long	x;
	long	y;
}	t_xy;

typedef struct s_xyd
{
	float	x;
	float	y;
}	t_xyd;

typedef struct s_all_texture
{
	char			*n_wall;
	char			*s_wall;
	char			*e_wall;
	char			*w_wall;
	unsigned long	*floor_color;
	unsigned long	*ceiling_color;
}	t_all_texture;

typedef struct s_cellule
{
	t_xy					position;
	t_element_map			element;
	struct s_cellule		*north;
	struct s_cellule		*south;
	struct s_cellule		*east;
	struct s_cellule		*west;
}	t_cellule;

typedef struct s_world_data
{
	t_cardinal		start_angle;
	char			initial_angle;
	t_cellule		*map;
	t_xy			spawn;
}	t_world_data;

typedef struct s_file_cub
{
	char	*path;
	int		nbr_line;
	char	**contained_by_line;
	int		fd;
	int		start_map;
}	t_file_cub;

typedef struct s_img
{
	void	*image;
	char	*addr;
	int		bitpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_color
{
	unsigned long	*path;
}	t_color;

typedef struct s_tex
{
	t_img		texture;
	double		wall_x;
	int			textx;
	int			texty;
	double		textstep;
	double		textpos;
	char		*color;
}	t_tex;

typedef struct s_minilibx
{
	void			*mlx;
	void			*win;
	long			sizex;
	long			sizey;
	t_img			img_mlx;

}	t_minilibx;

typedef struct s_data_file
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				aleft;
	int				aright;
	int				esc;
	int				keymap;
	t_xyd			raydir;
	t_xyd			rayplane;
	t_xyd			campos;
	t_xyd			camera;
	t_xyd			dir;
	t_xyd			map;
	t_xyd			delta;
	t_xyd			step;
	t_xyd			sidedist;
	double			distwall;
	int				line_height;
	int				hit;
	int				side;
	int				drawstart;
	int				drawend;
	char			**mapp;
	long			nb_max_col;
	long			nb_max_row;
	int				perimeter_size;
	t_xyd			bis;
	t_xyd			start;
	t_xyd			end;
	t_xyd			player;
	t_xyd			player_draw;
	t_img			img[4];
	t_color			rgb[2];

}	t_data_file;

typedef struct s_all_data
{
	t_error_code	err;
	t_file_cub		*fcb;
	t_all_texture	*textures;
	t_world_data	*world;
	t_data_file		*file;
	t_minilibx		*mini;
	t_img			*img;
	t_color			*color;
	t_tex			*tex;
}	t_all_data;

#endif
