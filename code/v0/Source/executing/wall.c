/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:08:06 by lazanett          #+#    #+#             */
/*   Updated: 2024/03/29 14:02:19 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

void	draw_wall(t_all_data *all)
{
	t_img	texture;
	int		i;

	texture = get_texture(all);
	if (all->file->side == 0)
		all->file->wall_x = all->world->spawn.y + all->file->distwall \
		* all->file->dir.y;
	else
		all->file->wall_x = all->world->spawn.x + all->file->distwall \
		* all->file->dir.x;
	all->file->wall_x -= floor(all->file->wall_x);
	init_wall(all);
	i = all->file->drawstart;
	while (i < all->file->drawend)
	{
		all->file->textY = (int)all->file->textPos & (all->img->height - 1);
		all->file->textPos += all->file->textStep;
	}
}

void	init_wall(t_all_data *all)
{
	all->file->textX = (int)(all->file->wall_x * all->img->width);
	if (all->file->side == 0 && all->file->dir.x > 0)
		all->file->textX = all->img->width - all->file->textX - 1;
	if (all->file->side == 1 && all->file->dir.y < 0)
		all->file->textX = all->img->width - all->file->textX - 1;
	all->file->textStep = 1.0 * all->img->height / all->file->line_height;
	all->file->textPos = (all->file->drawstart - all->mini->sizey / 2 + \
	all->file->line_height / 2) * all->file->textStep;
}