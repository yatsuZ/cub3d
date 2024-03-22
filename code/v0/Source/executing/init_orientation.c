/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_orientation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:11:18 by lazanett          #+#    #+#             */
/*   Updated: 2024/03/22 17:56:39 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

static void	init_orient2(t_all_data *all)
{
	if (all->world->start_angle == 83)
	{
		all->file->raydir.x = 0;
		all->file->raydir.y = 1;
		all->file->rayplane.x = 0.66;
		all->file->rayplane.y = 0;
	}
	if (all->world->start_angle == 78)
	{
		all->file->raydir.x = 0;
		all->file->raydir.y = -1;
		all->file->rayplane.x = -0.66;
		all->file->rayplane.y = 0;
	}
}

void	init_orient(t_all_data *all)
{
	all->world->spawn.x = all->file->campos.x + 0.1;
	all->world->spawn.y = all->file->campos.y + 0.1;
	if (all->world->start_angle == 87)
	{
		all->file->raydir.x = -1;
		all->file->raydir.y = 0;
		all->file->rayplane.x = 0;
		all->file->rayplane.y = 0.66;
	}
	if (all->world->start_angle == 69)
	{
		all->file->raydir.x = 1;
		all->file->raydir.y = 0;
		all->file->rayplane.x = 0;
		all->file->rayplane.y = -0.66;
	}
	init_orient2(all);
}
