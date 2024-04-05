/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:29:34 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/03 12:33:27 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

void	vision_left(t_all_data *all)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = all->file->raydir.x;
	all->file->raydir.x = all->file->raydir.x * cos(0.0250) \
	- all->file->raydir.y * sin(0.0250);
	all->file->raydir.y = old_dir_x * sin(0.0250) \
	+ all->file->raydir.y * cos(0.0250);
	old_plane_x = all->file->rayplane.x;
	all->file->rayplane.x = all->file->rayplane.x * cos(0.0250) \
	- all->file->rayplane.y * sin(0.0250);
	all->file->rayplane.y = old_plane_x * sin(0.0250) \
	+ all->file->rayplane.y * cos(0.0250);
}

void	vision_right(t_all_data *all)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = all->file->raydir.x;
	all->file->raydir.x = all->file->raydir.x * cos(-0.0250) \
	- all->file->raydir.y * sin(-0.0250);
	all->file->raydir.y = old_dir_x * sin(-0.0250) \
	+ all->file->raydir.y * cos(-0.0250);
	old_plane_x = all->file->rayplane.x;
	all->file->rayplane.x = all->file->rayplane.x * cos(-0.0250) \
	- all->file->rayplane.y * sin(-0.0250);
	all->file->rayplane.y = old_plane_x * sin(-0.0250) \
	+ all->file->rayplane.y * cos(-0.0250);
}