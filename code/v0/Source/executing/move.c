/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:53:50 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/03 12:09:56 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

void	go_straight(t_all_data *all)
{
	if (all->file->mapp[(int)(all->world->spawn.y + all->file->raydir.y \
	* 0.045)][(int)(all->world->spawn.x + all->file->raydir.x \
	* 0.045)] == 48 || is_dir(all->file->mapp[(int)(all->world->spawn.y \
	+ all->file->raydir.y \
	* 0.045)][(int)(all->world->spawn.x + all->file->raydir.x \
	* 0.045)]))
	{
		all->world->spawn.x += all->file->raydir.x * 0.045;
		all->world->spawn.y += all->file->raydir.y * 0.045;
		raycasting(all);
	}
}

void	go_back(t_all_data *all)
{
	if (all->file->mapp[(int)(all->world->spawn.y - all->file->raydir.y \
	* 0.045)][(int)(all->world->spawn.x - all->file->raydir.x \
	* 0.045)] == 48 || is_dir(all->file->mapp[(int)(all->world->spawn.y \
	- all->file->raydir.y \
	* 0.045)][(int)(all->world->spawn.x - all->file->raydir.x \
	* 0.045)]))
	{
		all->world->spawn.x -= all->file->raydir.x * 0.045;
		all->world->spawn.y -= all->file->raydir.y * 0.045;
		raycasting(all);
	}
}

void	go_left(t_all_data *all)
{
	if (all->file->mapp[(int)(all->world->spawn.y - all->file->rayplane.y \
	* 0.045)][(int)(all->world->spawn.x - all->file->rayplane.x\
	* 0.045)] == 48 || is_dir(all->file->mapp[(int)(all->world->spawn.y \
	- all->file->rayplane.y \
	* 0.045)][(int)(all->world->spawn.x - all->file->rayplane.x\
	* 0.045)]))
	{
		all->world->spawn.x -= all->file->rayplane.x* 0.045;
		all->world->spawn.y -= all->file->rayplane.y * 0.045;
		raycasting(all);
	}
}

void	go_right(t_all_data *all)
{
	if (all->file->mapp[(int)(all->world->spawn.y + all->file->rayplane.y \
	* 0.045)][(int)(all->world->spawn.x + all->file->rayplane.x\
	* 0.045)] == 48 || is_dir(all->file->mapp[(int)(all->world->spawn.y \
	+ all->file->rayplane.y \
	* 0.045)][(int)(all->world->spawn.x \
	+ all->file->rayplane.x\
	* 0.045)]))
	{
		all->world->spawn.x += all->file->rayplane.x* 0.045;
		all->world->spawn.y += all->file->rayplane.y * 0.045;
		raycasting(all);
	}
}

bool	is_dir(char c)
{
	if (c == 'E' || c == 'W' \
	|| c == 'S' || c == 'N')
		return (true);
	return (false);
}