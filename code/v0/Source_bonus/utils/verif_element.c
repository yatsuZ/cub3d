/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:20:36 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/16 14:46:52 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

t_error_code	verif_element_void(t_cellule *c)
{
	if (c == NULL)
		return (ERR_NULL);
	if (c->north && (c->north->element != VOID && c->north->element != WALL))
		return (ERR_WALL_NOT_CLOSE);
	if (c->south && (c->south->element != VOID && c->south->element != WALL))
		return (ERR_WALL_NOT_CLOSE);
	if (c->east && (c->east->element != VOID && c->east->element != WALL))
		return (ERR_WALL_NOT_CLOSE);
	if (c->west && (c->west->element != VOID && c->west->element != WALL))
		return (ERR_WALL_NOT_CLOSE);
	return (ERR_NULL);
}

t_error_code	verif_element_floor(t_cellule *c)
{
	if (c == NULL)
		return (ERR_NULL);
	if (!c->north || c->north->element == VOID)
		return (ERR_WALL_NOT_CLOSE);
	if (!c->south || c->south->element == VOID)
		return (ERR_WALL_NOT_CLOSE);
	if (!c->east || c->east->element == VOID)
		return (ERR_WALL_NOT_CLOSE);
	if (!c->west || c->west->element == VOID)
		return (ERR_WALL_NOT_CLOSE);
	return (ERR_NULL);
}

t_error_code	verif_element_spawn(t_cellule *c, t_world_data *w)
{
	if (c == NULL || !w)
		return (ERR_NULL);
	if (w->start_angle != IDK)
		return (ERR_REDUNDANCE_SPAWN);
	else if (c->element == SPAWN_N)
	{
		w->start_angle = NORTH;
		w->initial_angle = 'N';
	}
	else if (c->element == SPAWN_S)
	{
		w->start_angle = SOUTH;
		w->initial_angle = 'S';
	}
	else if (c->element == SPAWN_E)
	{
		w->start_angle = EAST;
		w->initial_angle = 'E';
	}
	else if (c->element == SPAWN_W)
	{
		w->start_angle = WEST;
		w->initial_angle = 'W';
	}
	return (w->spawn = c->position, verif_element_floor(c));
}
