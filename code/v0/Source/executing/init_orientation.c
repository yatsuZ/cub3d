/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_orientation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:11:18 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/05 15:34:40 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

static void	init_orient2(t_all_data *all)
{
	if (all->world->initial_angle == 83)
	{
		all->file->raydir.x = 0;
		all->file->raydir.y = 1;
		all->file->rayplane.x = (long)0.66;
		all->file->rayplane.y = 0;
	}
	if (all->world->initial_angle == 78)
	{
		all->file->raydir.x = 0;
		all->file->raydir.y = -1;
		all->file->rayplane.x = (long)-0.66;
		all->file->rayplane.y = 0;
	}

}

int	init_orient(t_all_data *all)
{
	alloc_mapp(all);
	all->color[FLOOR].path = all->textures->floor_color;
	if (!all->color[FLOOR].path)
		return (0);
	if (*all->textures->ceiling_color)
		printf("\n------ceiling color %lu \n", *all->textures->ceiling_color);
	all->color[CEIL].path = all->textures->ceiling_color;
	if (!all->color[CEIL].path)
		return (0);
	//printf("%ld   |   %ld\n", all->world->spawn.x, all->world->spawn.y);
	//printf("%f   |   %f\n", all->file->campos.x, all->file->campos.y);
	all->world->spawn.x = all->file->campos.x + 0.1;
	all->world->spawn.y = all->file->campos.y + 0.1;
	//printf("%ld   |   %ld\n", all->world->spawn.x, all->world->spawn.y);
	if (all->world->initial_angle == 87)
	{
		all->file->raydir.x = -1;
		all->file->raydir.y = 0;
		all->file->rayplane.x = 0;
		all->file->rayplane.y = (long)0.66;
	}
	if (all->world->initial_angle == 69)
	{
		all->file->raydir.x = 1;
		all->file->raydir.y = 0;
		all->file->rayplane.x = 0;
		all->file->rayplane.y = (long)-0.66;
	}
	init_orient2(all);
	return (1);
}
