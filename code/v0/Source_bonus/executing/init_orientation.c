/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_orientation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:11:18 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/19 16:44:42 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

int	init_orient(t_all_data *all)
{
	alloc_mapp(all);
	all->file->campos.x = all->world->spawn.y + 0.49f;
	all->file->campos.y = all->world->spawn.x + 0.49f;
	if (all->world->initial_angle == 87)
	{
		all->file->raydir.x = -1.0f;
		all->file->rayplane.y = -0.49f;
	}
	if (all->world->initial_angle == 69)
	{
		all->file->raydir.x = 1.0f;
		all->file->rayplane.y = 0.49f;
	}
	if (all->world->initial_angle == 83)
	{
		all->file->raydir.y = 1.0f;
		all->file->rayplane.x = -0.49f;
	}
	if (all->world->initial_angle == 78)
	{
		all->file->raydir.y = -1.0f;
		all->file->rayplane.x = 0.49f;
	}
	return (1);
}
