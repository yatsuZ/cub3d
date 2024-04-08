/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_orientation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:11:18 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/08 18:24:53 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

int	init_orient(t_all_data *all)
{
	alloc_mapp(all);
	all->file->campos.x = all->world->spawn.y  + 0.49f; //fix parsing
	all->file->campos.y = all->world->spawn.x + 0.49f; //fix parsing
	if (all->world->initial_angle == 87) // WE
	{
		all->file->raydir.x = -1.0f;
		all->file->rayplane.y = -0.49f;
	}
	if (all->world->initial_angle == 69) // EA
	{
		all->file->raydir.x = 1.0f;
		all->file->rayplane.y = 0.49f;
	}
	if (all->world->initial_angle == 83) // SO
	{
		all->file->raydir.y = 1.0f;
		all->file->rayplane.x = -0.49f;
	}
	if (all->world->initial_angle == 78) //NO
	{
		all->file->raydir.y = -1.0f;
		all->file->rayplane.x = 0.49f;
	}
	return (1);
}
