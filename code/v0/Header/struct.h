/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:31:35 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/21 11:59:52 by lazanett         ###   ########.fr       */
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
	t_cellule		*map;
	t_xy			spawn;
}	t_world_data ;

typedef struct s_file_cub
{
	char	*path;
	int		nbr_line;
	char	**contained_by_line;
	int		fd;
	int		start_map;
}	t_file_cub;

typedef struct s_data_file
{
	void			*mlx;
	void			*win;

	char			*north;
	char			*south;
	char			*west;
	char			*east;
	unsigned long	floor;
	unsigned long	ceiling;
	bool			floor_set;
	bool			ceiling_set;

	char			**map;
	char			**file;
	int				nbr_line;
	char			dir;
	double			pos_player_x;
	double			pos_player_y;
	double			dir_player_x;
	double			dir_player_y;
	double			plane_x;
	double			plane_y;
	int				has_moved;
	int				move_x;
	int				move_y;
	int				rotate;
	void			**img;
	int				**addr_img;
	int				pixel_bits[6];
	int				size_line[6];
	int				endian[6];
	double			camera_x;
	double			dir_ray_x;
	double			dir_ray_y;
	int				map_x;
	int				map_y;
	double			deltadist_x;
	double			deltadist_y;
	int				step_x;
	int				step_y;
	double			sidedist_x;
	double			sidedist_y;
	int				side;
	double			wall_dist;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				texture_dir;
	double			wall_x;
	double			step;
	int				texx;
	int				texy;
	int				texpos;
}	t_data_file;

typedef struct s_all_data
{
	t_error_code	err;
	t_file_cub		*fcb;
	t_all_texture	*textures;
	t_world_data	*world;
	t_data_file		*file;
}	t_all_data;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;




#endif