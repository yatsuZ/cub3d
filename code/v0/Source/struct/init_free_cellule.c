/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_cellule.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:49:54 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/15 00:21:31 by yzaoui           ###   ########.fr       */
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
	(*cellule)->i = -1;
	(*cellule)->j = -1;
	if (!(char_allowed(c) && c != '\n'))
		return (*err = ERR_BAD_SYNTAXE_MAP, 1);
	if (c == ' ')
		(*cellule)->element = VOID;
	else if (c == '0')
		(*cellule)->element = FLOOR_E;
	else if (c == '1')
		(*cellule)->element = WALL;
	else
		(*cellule)->element = SPAWN;
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

int	init_all_cellules(t_cellule **cellule, char **txt, int i, int j, t_error_code *err)
{
	if (!cellule || !txt || !err || *err != ERR_NULL)
		return (1);
	if (txt[i] == NULL || j < 0 || txt[i][j] == '\0' || txt[i][j] == '\n')
		return (0);
	init_cellule(cellule, txt[i][j], err);
	if (*err != ERR_NULL)
		return (1);
	(*cellule)->j = j;
	(*cellule)->i = i;
	j = j + 1;
	init_all_cellules(&((*cellule)->east), txt, i, j, err);
	if ((*cellule)->east)
		(*cellule)->east->west = (*cellule);
	i = i + 1;
	if (j == 1)
		init_all_cellules(&((*cellule)->south), txt, i, 0, err);
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
	(*cellule)->i = -1;
	(*cellule)->j = -1;
	free(*cellule);
	*cellule = NULL;
}

