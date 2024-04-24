/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:47:04 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/22 11:49:59 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./macro.h"

// INIT structure

//------------- STRUCT : ALL

int				init_all(t_all_data **all, char *path_file);
void			free_all(t_all_data **all);

//------------- STRUCT : FILE CUB

int				init_file_cub(char *path, t_error_code *err, t_file_cub **fcb);
void			free_file_cub(t_file_cub **fcb);

//------------- STRUCT : ALL TEXTURE

int				init_all_texture(t_file_cub *fcb, t_error_code *err, \
t_all_texture **textures);
t_error_code	get_orientation_texture(char *line, t_texture textu, \
t_all_texture *all_t);
t_error_code	get_rgb_texture(char *line, t_texture texture, \
t_all_texture *all_t);
void			free_all_texture(t_all_texture **textures);

//------------ STRUCT : WORLD

int				init_world(t_file_cub *fcb, t_error_code *err, \
t_world_data **world);
void			free_world(t_world_data **world);

//------------ STRUCT : CELLULE

int				init_all_cellules(t_cellule **cellule, char **txt, \
t_xy p, t_error_code *err);
void			free_all_cellules(t_cellule **cellule);
t_error_code	for_each_cellule(t_cellule *c, t_world_data *w, \
t_error_code (*f)(t_cellule *, t_world_data *));

//------------ STRUCT : IMG

int				init_img(t_error_code *err, t_img **img);
void			free_img(t_img *img);

//------------ STRUCT : DATA_FILE

int				init_data_file(t_error_code *err, t_data_file **file);
void			free_data_file(t_all_data *all);
t_error_code	alloc_mapp(t_all_data *all);

//------------ STRUCT : MINILIBX

int				init_minilibx(t_error_code *err, t_minilibx **mini);
void			free_minilibx(t_all_data *all, t_minilibx **mini);

//------------ STRUCT : COLOR
int				init_color(t_error_code *err, t_color **rgb);
void			free_color(t_color *rgb);

//------------ STRUCT : TEX
int				init_tex(t_error_code *err, t_tex **tex);
void			free_tex(t_tex *tex);
// FT FOR PARSSING

t_error_code	check_is_file_and_extension(char *arg, \
t_extension_file option);

// Error gestion

void			show_end(t_error_code err);

// Verification des elements

t_error_code	verif_element_spawn(t_cellule *c, t_world_data *w);
t_error_code	verif_element_floor(t_cellule *c);
t_error_code	verif_element_void(t_cellule *c);

// FT UTILS

int				size_path(char *line);
bool			is_empty_line(char *line);
int				skip_space(char *line);
void			free_tab_char(char **tableau, int len);
bool			is_number_array(char **tab, int i);
bool			is_a_legit_line_map(char *str);
int				size_tab(char **tab);
t_element_map	define_element(char c);
bool			char_allowed(char c);

// OLD FT UTILS

void			*ft_memset(void *s, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
size_t			ft_strlen(const char *cha);
bool			ft_strcmp(char *s1, char *s2, long size);
char			*get_next_line(int fd, int err);
int				ft_atoi(const char *nptr);
char			*ft_strdup(const char *s);
int				ft_isdigit(int character);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(const char *s, char c);

// GNL UTILS

char			*ft_memcpy2(char *dest, char *src, int n);
char			*ft_strjoin2(char *s1, char *s2);
char			*ft_strdup2(char *s, int option);
void			*ft_calloc2(int nmemb, int size);
int				ft_strlen_or_findendl(char *s, int option);

// Debeugage

void			put_color_txt(t_color_texte color);
void			show_file_cub(t_file_cub *fcb);
void			show_texture(t_all_texture *textures);
void			show_world(t_world_data *w);
void			show_cellule(t_cellule *c);

// EXECUTING
//----start.c
t_error_code	start_exec(t_all_data *all);
t_error_code	init_execution(t_all_data *all);
int				ft_game(t_all_data *all);
void			screen_size(t_all_data *all);

//----key.c
int				key_press(int keycode, t_data_file *file);
int				key_drop(int keycode, t_data_file *file);
int				ft_key(t_all_data *all);
int				escape(t_all_data *all);

//----move.c
void			go_straight(t_all_data *all);
void			go_back(t_all_data *all);
void			go_left(t_all_data *all);
void			go_right(t_all_data *all);
bool			is_dir(char c);

//----init_orientation.c
int				init_orient(t_all_data *all);

//----conv_texture.c
int				convertion_image(t_all_data *all);
int				get_adress_img(t_all_data *all);
void			free_image(t_all_data *all);

//----raycasting.c
void			raycasting(t_all_data *all);

// double	conv_neg(double n);
float			conv_neg(float n);

//----raycasting_utils.c
void			init_dda(t_all_data *all, int i);
void			calcul_delta(t_all_data *all);
void			perform_dda(t_all_data *all);
void			handle_no_colision(t_all_data *all);
void			limit_wall_height(t_all_data *all);

//----texture.c
t_img			get_texture_tab(t_all_data *all);
int				rbg_hexa(t_all_data *all, int i);
void			img_pix_put(t_img *img, int x, int y, unsigned long color);

//----vision.c
void			vision_left(t_all_data *all);
void			vision_right(t_all_data *all);

//----wall.c
void			draw_wall(t_all_data *all, int j);
t_tex			init_draw_wall(t_all_data *all);
void			draw_void(t_all_data *all);
double			get_wallx(t_all_data *all);

// MAIN
int				end(t_all_data *all);

#endif
