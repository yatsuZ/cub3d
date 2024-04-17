/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:29:34 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/17 17:08:13 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

void	vision_left(t_all_data *all)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = all->file->raydir.x;
	all->file->raydir.x = all->file->raydir.x * cos(0.0150) \
	- all->file->raydir.y * sin(0.0150);
	all->file->raydir.y = old_dir_x * sin(0.0150) \
	+ all->file->raydir.y * cos(0.0150);
	old_plane_x = all->file->rayplane.x;
	all->file->rayplane.x = all->file->rayplane.x * cos(0.0150) \
	- all->file->rayplane.y * sin(0.0150);
	all->file->rayplane.y = old_plane_x * sin(0.0150) \
	+ all->file->rayplane.y * cos(0.0150);
}

void	vision_right(t_all_data *all)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = all->file->raydir.x;
	all->file->raydir.x = all->file->raydir.x * cos(-0.0150) \
	- all->file->raydir.y * sin(-0.0150);
	all->file->raydir.y = old_dir_x * sin(-0.0150) \
	+ all->file->raydir.y * cos(-0.0150);
	old_plane_x = all->file->rayplane.x;
	all->file->rayplane.x = all->file->rayplane.x * cos(-0.0150) \
	- all->file->rayplane.y * sin(-0.0150);
	all->file->rayplane.y = old_plane_x * sin(-0.0150) \
	+ all->file->rayplane.y * cos(-0.0150);
}

void	mouse_pov(t_all_data *all)
{
	int	pos_x;
	int	pos_y;

	mlx_mouse_get_pos(all->mini->mlx, all->mini->win, &pos_x, &pos_y);
	if (pos_x <= ((int)all->mini->sizex / 3)
		&& (pos_y >= all->mini->sizey / 10))
		all->file->aleft = 1;
	else if (pos_x >= (((int)all->mini->sizex / 3) * 2)
		&& (pos_y >= all->mini->sizey / 10))
		all->file->aright = 1;
	else if (pos_y <= ((int)all->mini->sizey / 3) && (pos_x >= \
	all->mini->sizex / 3) && (pos_x <= ((int)all->mini->sizex / 3) * 2))
		all->file->up = 1;
	else if (pos_y >= (((int)all->mini->sizey / 3) * 2) && (pos_x >= \
	all->mini->sizex / 3) && (pos_x <= ((int)all->mini->sizex / 3) * 2))
		all->file->down = 1;
	else
	{
		all->file->aleft = 0;
		all->file->aright = 0;
		all->file->up = 0;
		all->file->down = 0;
	}
	return ;
}
