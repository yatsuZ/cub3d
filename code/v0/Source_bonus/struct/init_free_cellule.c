/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_cellule.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:49:54 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/15 00:35:19 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

static int	init_cellule(t_cellule **cellule, char c, t_error_code *err)
{
	if (!cellule || !err || *err != ERR_NULL)
		return (1);
	*cellule = ft_calloc(1, sizeof(t_cellule));
	if (*cellule == NULL)
		return (*err = ERR_MALLOC, 1);
	(*cellule)->north = NULL;
	(*cellule)->south = NULL;
	(*cellule)->east = NULL;
	(*cellule)->west = NULL;
	(*cellule)->position.x = -1;
	(*cellule)->position.y = -1;
	if (!(CHAR_ALLOWED(c)))
		return (*err = ERR_BAD_SYNTAXE_MAP, 1);
	(*cellule)->element = define_element(c);
	return (0);
}

static void	connect_north_south(t_cellule *n, t_cellule *s)
{
	while (n && s)
	{
		n->south = s;
		s->north = n;
		n = n->east;
		s = s->east;
	}
}

int	init_all_cellules(t_cellule **cellule, char **txt, \
t_xy p, t_error_code *err)
{
	if (!cellule || !txt || !err || *err != ERR_NULL)
		return (1);
	if (txt[p.x] == NULL || p.y < 0 || \
	txt[p.x][p.y] == '\0')
		return (0);
	init_cellule(cellule, txt[p.x][p.y], err);
	if (*err != ERR_NULL)
		return (1);
	(*cellule)->position = p;
	p.y = p.y + 1;
	init_all_cellules(&((*cellule)->east), txt, p, err);
	if ((*cellule)->east)
		(*cellule)->east->west = (*cellule);
	p.x = p.x + 1;
	if (p.y == 1)
	{
		p.y = 0;
		init_all_cellules(&((*cellule)->south), txt, p, err);
	}
	if ((*cellule)->south)
		(*cellule)->south->north = (*cellule);
	connect_north_south(*cellule, (*cellule)->south);
	return (*err != ERR_NULL);
}

void	free_all_cellules(t_cellule **cellule)
{
	if (!cellule || !*cellule)
		return ;
	if ((*cellule)->west == NULL)
		free_all_cellules(&((*cellule)->south));
	free_all_cellules(&((*cellule)->east));
	(*cellule)->north = NULL;
	(*cellule)->south = NULL;
	(*cellule)->east = NULL;
	(*cellule)->west = NULL;
	(*cellule)->position.x = -1;
	(*cellule)->position.y = -1;
	free(*cellule);
	*cellule = NULL;
}

t_error_code	for_each_cellule(t_cellule *c, t_world_data *w, \
t_error_code (*f)(t_cellule *, t_world_data *))
{
	t_error_code	err;

	err = ERR_NULL;
	if (!c || !w || !f)
		return (err);
	err = f(c, w);
	if (err != ERR_NULL)
		return (err);
	if (c->east)
		err = for_each_cellule(c->east, w, f);
	if (c->west == NULL && err == ERR_NULL)
		err = for_each_cellule(c->south, w, f);
	return (err);
}
