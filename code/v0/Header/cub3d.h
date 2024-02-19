/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:47:04 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/20 00:12:53 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./struct.h"


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

int				init_all_cellules(t_cellule **cellule, char **txt, int i, int j, t_error_code *err);
void			free_all_cellules(t_cellule **cellule);

// FT FOR PARSSING

t_error_code	check_is_file_and_extension(char *arg, t_extension_file option);

// Error gestion

void		show_end(t_error_code err);

// FT UTILS

int			size_path(char *line);
bool		is_empty_line(char *line);
int			skip_white_space(char *line);
void		free_tab_char(char **tableau, int len);
bool		is_number_array(char **tab, int i);
bool		char_allowed(char c);
bool		is_a_legit_line_map(char *str);
int			size_tab(char **tab);

// OLD FT UTILS

void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlen(const char *cha);
bool		ft_strcmp(char *s1, char *s2);
char		*get_next_line(int fd, int err);
int			ft_atoi(const char *nptr);
char		*ft_strdup(const char *s);
int			ft_isdigit(int character);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(const char *s, char c);

// Debeugage

void		put_color_txt(t_color_texte color);
void		show_file_cub(t_file_cub *fcb);
void		show_texture(t_all_texture *textures);
void		show_world(t_world_data *w);
void		show_cellule(t_cellule *c);

#endif