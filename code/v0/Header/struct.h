/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:31:35 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/29 13:59:39 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./import.h"

typedef struct s_xy
{
	long	x;
	long	y;
}	t_xy;

typedef struct s_xyd
{
	double	x;
	double	y;
}	t_xyd;

typedef struct s_all_texture
{
	char			*n_wall; // path
	char			*s_wall; // path
	char			*e_wall;// path
	char			*w_wall;// path
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
	t_cardinal		start_angle; // repere quell pos il a 
	t_cellule		*map; // carte
	t_xy			spawn; // camera/joueur
}	t_world_data ;

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
	///-----KEY-----///
	int				up;
	int				down;
	int				left;
	int				right;
	int				aleft;
	int				aright;
	int				esc;

	t_xyd			raydir; //init
	t_xyd			rayplane;//init
	t_xyd			campos; // init
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
	t_img			img[4];

	double			wall_x;
	int				textX;
	int				textY;
	double			textStep;
	double			textPos;
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
}	t_all_data;

#endif