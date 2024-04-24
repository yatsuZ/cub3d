/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_texture_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:59:58 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/23 14:47:50 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

static unsigned long	rgb_to_long(int r, int g, int b)
{
	unsigned long	res;

	res = ((r & 0xff) << 16);
	res = res + ((g & 0xff) << 8);
	res = res + (b & 0xff);
	return (res);
}

static t_error_code
	set_rgb_color(t_all_texture *all_t, char **rgb_tab, t_texture texture)
{
	int	rgb[3];
	int	i;

	i = 0;
	rgb[0] = ft_atoi(rgb_tab[0]);
	rgb[1] = ft_atoi(rgb_tab[1]);
	rgb[2] = ft_atoi(rgb_tab[2]);
	while (i < 3)
	{
		if (rgb[i] > 255 || rgb[i] < 0)
			return (ERR_BAD_SYNTAXE_TEXTURE);
		i++;
	}
	if (texture == FLOOR_T)
		*(all_t->floor_color) = rgb_to_long(rgb[0], rgb[1], rgb[2]);
	else if (texture == CEILING_T)
		*(all_t->ceiling_color) = rgb_to_long(rgb[0], rgb[1], rgb[2]);
	return (ERR_NULL);
}

t_error_code
	get_rgb_texture(char *line, t_texture texture, t_all_texture *all_t)
{
	int				i;
	t_error_code	err;
	char			**rgb_tab;

	if (all_t->floor_color == NULL && texture == FLOOR_T)
		all_t->floor_color = ft_calloc(1, sizeof(unsigned long));
	else if (all_t->ceiling_color == NULL && texture == CEILING_T)
		all_t->ceiling_color = ft_calloc(1, sizeof(unsigned long));
	else
		return (ERR_SAME_TEXTURE);
	if ((all_t->ceiling_color == NULL && texture == CEILING_T) || \
	(all_t->floor_color == NULL && texture == FLOOR_T))
		return (ERR_MALLOC);
	i = skip_space(line) + 2;
	i += skip_space(line + i);
	rgb_tab = ft_split(line + i, ',');
	if (!rgb_tab)
		return (ERR_MALLOC);
	if (!is_number_array(rgb_tab, 0) || size_tab(rgb_tab) < 3)
		return (free_tab_char(rgb_tab, -1), ERR_BAD_SYNTAXE_TEXTURE);
	err = set_rgb_color(all_t, rgb_tab, texture);
	return (free_tab_char(rgb_tab, -1), err);
}
