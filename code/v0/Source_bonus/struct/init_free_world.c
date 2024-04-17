/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:49:09 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/16 14:46:21 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

static bool	is_a_legit_syntaxe_map(char **texte, int start_i)
{
	int		i;

	i = start_i;
	while (texte[i])
	{
		if (is_a_legit_line_map(texte[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

static t_error_code	legit_map(t_cellule *c, t_world_data *w)
{
	t_error_code	err;

	err = ERR_NULL;
	if (w == NULL || c == NULL)
		return (err);
	if (c->element == UNKNOW)
		err = ERR_BAD_SYNTAXE_MAP;
	else if (c->element == VOID)
		err = verif_element_void(c);
	else if (c->element >= SPAWN_N && c->element <= SPAWN_W)
		err = verif_element_spawn(c, w);
	else if (c->element == FLOOR_E)
		err = verif_element_floor(c);
	return (err);
}

int	init_world(t_file_cub *fcb, t_error_code *err, t_world_data **world)
{
	t_xy	p;

	if (!world || !err || !fcb || *err != ERR_NULL)
		return (1);
	*world = ft_calloc(1, sizeof(t_world_data));
	if (!(*world))
		return (*err = ERR_MALLOC, 1);
	(*world)->spawn.x = -1;
	(*world)->spawn.y = -1;
	(*world)->start_angle = IDK;
	(*world)->initial_angle = 0;
	(*world)->map = NULL;
	if (is_a_legit_syntaxe_map(fcb->contained_by_line, fcb->start_map) == false)
		return (*err = ERR_BAD_SYNTAXE_MAP);
	p.x = fcb->start_map;
	p.y = 0;
	init_all_cellules(&(*world)->map, fcb->contained_by_line, p, err);
	if (*err != ERR_NULL)
		return (1);
	*err = for_each_cellule((*world)->map, (*world), legit_map);
	if (*err == ERR_NULL && (*world)->start_angle == IDK)
		*err = ERR_MISSING_SPAWN;
	(*world)->spawn.x = (*world)->spawn.x - fcb->start_map;
	return (*err != ERR_NULL);
}

void	free_world(t_world_data **world)
{
	if (!world || !*world)
		return ;
	free_all_cellules(&(*world)->map);
	free(*world);
	*world = NULL;
}
