/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 03:12:51 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/14 16:38:43 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

static void	show_rgb(unsigned long rgb)
{
	int	red;
	int	green;
	int	blue;

	red = (rgb >> 16) & 0xff;
	green = (rgb >> 8) & 0xff;
	blue = rgb & 0xff;
	printf("RED = %d\t", red);
	printf("GREEN = %d\t", green);
	printf("BLUE = %d\n", blue);
}

void	show_texture(t_all_texture *textures)
{
	printf("North path texture\t= %s\n", textures->n_wall);
	printf("South path texture\t= %s\n", textures->s_wall);
	printf("East  path texture\t= %s\n", textures->e_wall);
	printf("West  path texture\t= %s\n", textures->w_wall);
	printf("Floor   adresse\t\t= %p", textures->floor_color);
	if (textures->floor_color)
	{
		printf(" | Floor   rgb = ");
		show_rgb(*(textures->floor_color));
	}
	else
		printf("\n");
	printf("Ceiling adresse\t\t= %p", textures->ceiling_color);
	if (textures->ceiling_color)
	{
		printf(" | Ceiling rgb = ");
		show_rgb(*(textures->ceiling_color));
	}
	else
		printf("\n");
}
