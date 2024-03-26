/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:47:04 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/26 13:43:27 by lazanett         ###   ########.fr       */
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

int				init_all_texture(t_file_cub *fcb, t_error_code *err, t_all_texture **textures);
t_error_code	get_orientation_texture(char *line, t_texture textu, t_all_texture *all_t);
t_error_code	get_rgb_texture(char *line, t_texture texture, t_all_texture *all_t);
void			free_all_texture(t_all_texture **textures);

//------------ STRUCT : WORLD

int				init_world(t_file_cub *fcb, t_error_code *err, t_world_data **world);
void			free_world(t_world_data **world);

//------------ STRUCT : CELLULE

int				init_all_cellules(t_cellule **cellule, char **txt, t_xy p, t_error_code *err);
void			free_all_cellules(t_cellule **cellule);
t_error_code	for_each_cellule(t_cellule *c, t_world_data *w, \
t_error_code (*f)(t_cellule *, t_world_data *));

//------------ STRUCT : IMG

int		init_img(t_error_code *err, t_img **img);
void	free_img(t_img *img);

//------------ STRUCT : DATA_FILE

int		init_data_file(t_error_code *err, t_data_file **file);
void	free_data_file(t_data_file *file);

//------------ STRUCT : MINILIBX

int		init_minilibx(t_error_code *err, t_minilibx **mini);
void	free_minilibx(t_all_data *all, t_minilibx **mini);


// FT FOR PARSSING

t_error_code	check_is_file_and_extension(char *arg, t_extension_file option);

// Error gestion

void		show_end(t_error_code err);

// Verification des elements

t_error_code	verif_element_spawn(t_cellule *c, t_world_data *w);
t_error_code	verif_element_floor(t_cellule *c);
t_error_code	verif_element_void(t_cellule *c);

// FT UTILS

int			size_path(char *line);
bool		is_empty_line(char *line);
int			skip_space(char *line);
void		free_tab_char(char **tableau, int len);
bool		is_number_array(char **tab, int i);
bool		is_a_legit_line_map(char *str);
int			size_tab(char **tab);
t_element_map
			define_element(char c);

// OLD FT UTILS

void	*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlen(const char *cha);
bool		ft_strcmp(char *s1, char *s2, long size);
char		*get_next_line(int fd, int err);
int			ft_atoi(const char *nptr);
char		*ft_strdup(const char *s);
int			ft_isdigit(int character);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(const char *s, char c);

// GNL UTILS

char	*ft_memcpy2(char *dest, char *src, int n);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strdup2(char *s, int option);
void	*ft_calloc2(int nmemb, int size);
int		ft_strlen_or_findendl(char *s, int option);

// Debeugage

void		put_color_txt(t_color_texte color);
void		show_file_cub(t_file_cub *fcb);
void		show_texture(t_all_texture *textures);
void		show_world(t_world_data *w);
void		show_cellule(t_cellule *c);

// EXECUTING
//----start.c
t_error_code	start_exec(t_all_data *all);
void	screen_size(t_all_data *all);

//----key.c
int		key_press(int keycode, t_data_file *all);
int		key_drop(int keycode, t_data_file *all);
int		ft_key(int keycode, t_all_data *all);
int		escape(t_all_data *all);

//----init_orientation.c
void	init_orient(t_all_data *all);

//----conv_texture.c
int		convertion_image(t_all_data *all);
int		get_adress_img(t_all_data *all);
void	img_pix_put(t_img *img, int x, int y, int color);
void	free_image(t_all_data *all);

// MAIN
int	end(t_all_data *all);

#endif
