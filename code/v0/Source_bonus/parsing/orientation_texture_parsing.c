/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation_texture_parsing.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:43:39 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/16 14:45:11 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

static t_error_code
	fill_texture_path(t_all_texture *all_t, char *path, t_texture textu)
{
	if (textu == NORTH_T && !all_t->n_wall)
		all_t->n_wall = path;
	else if (textu == NORTH_T)
		return (free(path), ERR_SAME_TEXTURE);
	else if (textu == SOUTH_T && !all_t->s_wall)
		all_t->s_wall = path;
	else if (textu == SOUTH_T)
		return (free(path), ERR_SAME_TEXTURE);
	else if (textu == EAST_T && !all_t->e_wall)
		all_t->e_wall = path;
	else if (textu == EAST_T)
		return (free(path), ERR_SAME_TEXTURE);
	else if (textu == WEST_T && !all_t->w_wall)
		all_t->w_wall = path;
	else if (textu == WEST_T)
		return (free(path), ERR_SAME_TEXTURE);
	return (ERR_NULL);
}

t_error_code
	get_orientation_texture(char *line, t_texture textu, t_all_texture *all_t)
{
	char			*path;
	int				i;

	i = skip_space(line) + 3;
	i += skip_space(line + i);
	path = ft_substr(line, i, size_path(line + i));
	if (!path)
		return (ERR_MALLOC);
	return (fill_texture_path(all_t, path, textu));
}
