/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:05:48 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/13 17:58:10 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

void	show_cardinal(t_cardinal c)
{
	if (c == IDK)
		printf("JE NE SAIS PAS ?\n");
	else if (c == NORTH)
	{
		put_color_txt(BLEU);
		printf("NORD\n");
	}
	else if (c == SOUTH)
	{
		put_color_txt(ROUGE);
		printf("SUD\n");
	}
	else if (c == EAST)
	{
		put_color_txt(VERT);
		printf("EST\n");
	}
	else if (c == WEST)
	{
		put_color_txt(BLANC);
		printf("OUEST\n");
	}
	put_color_txt(EMPTY_COLOR);
}

void	show_element(t_element_map em)
{
	if (em == UNKNOW)
		printf("?");
	else if (em == VOID)
	{
		put_color_txt(BLEU);
		printf("V");
	}
	else if (em == WALL)
	{
		put_color_txt(ROUGE);
		printf("M");
	}
	else if (em == SPAWN)
	{
		put_color_txt(JAUNE);
		printf("S");
	}
	else if (em == FLOOR_E)
	{
		put_color_txt(VERT);
		printf("F");
	}
	put_color_txt(EMPTY_COLOR);
}

void	show_map_2d(t_cellule *c)
{
	if (!c)
		return ;
	show_element(c->element);
	show_map_2d(c->east);
	if (c->east == NULL)
		printf("\n");
	if (c->west == NULL)
		show_map_2d(c->south);
}

void	show_cellule(t_cellule *c)
{
	printf("-----------------\
	\nAdresse = %p, i = %ld | j = %ld | ELEMENT = "\
	, c, c->position.x, c->position.y);
	show_element(c->element);
	printf("\n");
	put_color_txt(BLEU);
	printf("NORD = %p\t| ", c->north);
	put_color_txt(ROUGE);
	printf("SUD = %p\t| ", c->south);
	put_color_txt(VERT);
	printf("EST = %p\t| ", c->east);
	put_color_txt(JAUNE);
	printf("OUEST = %p\t|\n", c->west);
	put_color_txt(EMPTY_COLOR);
}

void	show_world(t_world_data *w)
{
	if (!w)
		return ;
	show_map_2d(w->map);
	printf("START Spawn\ni = %d\t|j = %d\n", w->i_spawn, w->j_spawn);
	printf("La direction de depart : ");
	show_cardinal(w->start_angle);
}
