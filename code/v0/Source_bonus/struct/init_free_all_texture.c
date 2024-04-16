/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_all_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 00:32:37 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/25 16:00:29 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

static t_texture	get_type_texture(char *line, bool *legit_line)
{
	int	j;

	if (!line)
		return (*legit_line = true, IDK_T);
	j = skip_space(line);
	if (ft_strcmp(line + j, "NO ", 3))
		return (NORTH_T);
	else if (ft_strcmp(line + j, "SO ", 3))
		return (SOUTH_T);
	else if (ft_strcmp(line + j, "WE ", 3))
		return (WEST_T);
	else if (ft_strcmp(line + j, "EA ", 3))
		return (EAST_T);
	else if (ft_strcmp(line + j, "F ", 2))
		return (FLOOR_T);
	else if (ft_strcmp(line + j, "C ", 2))
		return (CEILING_T);
	if (line[j + 1] == '\0')
		*legit_line = true;
	return (IDK_T);
}

static \
int	get_texture(char **contenu, t_error_code *err, t_all_texture *textures)
{
	t_texture	tmp;
	bool		legit_line;
	int			i;

	i = 0;
	while (contenu[i] && *err == ERR_NULL)
	{
		legit_line = false;
		tmp = get_type_texture(contenu[i], &legit_line);
		if (tmp != IDK_T && tmp != FLOOR_T && tmp != CEILING_T)
			*err = get_orientation_texture(contenu[i], tmp, textures);
		else if (tmp != IDK_T)
			*err = get_rgb_texture(contenu[i], tmp, textures);
		else if (is_empty_line(contenu[i]) == false)
		{
			if (is_a_legit_line_map(contenu[i]))
				return (i);
			*err = ERR_BAD_SYNTAXE_TEXTURE;
			return (i);
		}
		i++;
	}
	return (-1);
}

void	free_all_texture(t_all_texture **textures)
{
	if (!textures || !(*textures))
		return ;
	free((*textures)->n_wall);
	(*textures)->n_wall = NULL;
	free((*textures)->s_wall);
	(*textures)->s_wall = NULL;
	free((*textures)->e_wall);
	(*textures)->e_wall = NULL;
	free((*textures)->w_wall);
	(*textures)->w_wall = NULL;
	free((*textures)->floor_color);
	(*textures)->floor_color = NULL;
	free((*textures)->ceiling_color);
	(*textures)->ceiling_color = NULL;
	free(*textures);
	*textures = NULL;
}

int	init_all_texture(t_file_cub *fcb, t_error_code *err, \
t_all_texture **textures)
{
	if (!textures || !err || !fcb || *err != ERR_NULL)
		return (1);
	*textures = ft_calloc(1, sizeof(t_all_texture));
	if (!(*textures))
		return (*err = ERR_MALLOC, 1);
	(*textures)->n_wall = NULL;
	(*textures)->s_wall = NULL;
	(*textures)->e_wall = NULL;
	(*textures)->w_wall = NULL;
	(*textures)->floor_color = NULL;
	(*textures)->ceiling_color = NULL;
	fcb->start_map = get_texture(fcb->contained_by_line, err, *textures);
	if (*err != ERR_NULL)
		return (1);
	if (!(*textures)->n_wall || !(*textures)->s_wall || \
	!(*textures)->e_wall || !(*textures)->w_wall || \
	!(*textures)->ceiling_color || !(*textures)->floor_color)
		return (*err = ERR_MISSING_TEXTURE, 1);
	else if (check_is_file_and_extension((*textures)->n_wall, XPM)
		|| check_is_file_and_extension((*textures)->s_wall, XPM)
		|| check_is_file_and_extension((*textures)->e_wall, XPM)
		|| check_is_file_and_extension((*textures)->w_wall, XPM))
		return (*err = ERR_INVALID_FILE, 1);
	return (0);
}
