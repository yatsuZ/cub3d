/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:09:45 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/15 17:05:34 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

void	init_dda(t_all_data *all, int i)
{
	all->file->camera.x = 2 * i / (float)all->mini->sizex - 1.0f;
	all->file->dir.x = all->file->raydir.x + (all->file->rayplane.x \
		* all->file->camera.x);
	all->file->dir.y = all->file->raydir.y + (all->file->rayplane.y \
		* all->file->camera.x);
	all->file->map.x = (int)all->file->campos.x;
	all->file->map.y = (int)all->file->campos.y;
	all->file->hit = 0;
}

void	calcul_delta(t_all_data *all)
{
	if (all->file->dir.x == 0.0f)
		all->file->delta.x = 1e30;
	else
		all->file->delta.x = conv_neg(1 / all->file->dir.x);
	if (all->file->dir.y == 0.0f)
		all->file->delta.y = 1e30;
	else
		all->file->delta.y = conv_neg(1 / all->file->dir.y);
}

void	perform_dda(t_all_data *all)
{
	if (all->file->dir.x < 0)
	{
		all->file->step.x = -1;
		all->file->sidedist.x = (all->file->campos.x - all->file->map.x) * \
				all->file->delta.x;
	}
	else
	{
		all->file->step.x = 1;
		all->file->sidedist.x = (all->file->map.x + 1.0f - \
		all->file->campos.x) * all->file->delta.x;
	}
	if (all->file->dir.y < 0)
	{
		all->file->step.y = -1;
		all->file->sidedist.y = (all->file->campos.y - \
		all->file->map.y) * all->file->delta.y;
	}
	else
	{
		all->file->step.y = 1;
		all->file->sidedist.y = (all->file->map.y + 1.0f - \
		all->file->campos.y) * all->file->delta.y;
	}
}

void	handle_no_colision(t_all_data *all)
{
	while (all->file->hit == 0)
	{
		if (all->file->sidedist.x < all->file->sidedist.y)
		{
			all->file->sidedist.x += all->file->delta.x;
			all->file->map.x += all->file->step.x;
			all->file->side = 0;
		}
		else
		{
			all->file->sidedist.y += all->file->delta.y;
			all->file->map.y += all->file->step.y;
			all->file->side = 1;
		}
		if ((all->file->mapp[(int)all->file->map.y][(int)all->file->map.x]) \
			== '1' && (all->file->mapp[(int)all->file->map.y] \
			[(int)all->file->map.x]) != all->world->initial_angle)
			all->file->hit = 1;
	}
}

void	limit_wall_height(t_all_data *all)
{
	if (all->file->side == 0)
		all->file->distwall = (all->file->sidedist.x - all->file->delta.x);
	else
		all->file->distwall = (all->file->sidedist.y - all->file->delta.y);
	all->file->line_height = (int)(all->mini->sizey / all->file->distwall);
	all->file->drawstart = -all->file->line_height / 2 + all->mini->sizey / 2;
	if (all->file->drawstart < 0)
		all->file->drawstart = 0;
	all->file->drawend = all->file->line_height / 2 + all->mini->sizey / 2;
	if (all->file->drawend >= all->mini->sizey)
		all->file->drawend = all->mini->sizey -1;
}
