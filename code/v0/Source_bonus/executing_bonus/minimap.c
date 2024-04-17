/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:51:53 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/17 18:08:04 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

void	draw_minimap(t_all_data *all, int y, int x)
{
	int		current_y_bis;
	char	cell;

	init_minimap(all);
	current_y_bis = all->file->bis.y;
	y = all->file->start.y;
	while (y < all->file->end.y)
	{
		all->file->bis.x = 0;
		x = all->file->start.x;
		while (x < all->file->end.x)
		{
			cell = all->file->mapp[y][x];
			if (cell == '1')
				draw_square(all, current_y_bis, all->file->bis.x, 0xACAAA8);
			else if (cell == '0' || is_dir(cell))
				draw_square(all, current_y_bis, all->file->bis.x, 0xFFF7F7);
			x++;
			all->file->bis.x += 5;
		}
		current_y_bis += 5;
		y++;
	}
	draw_cam_minimap(all);
}

void	draw_square(t_all_data *all, int y, int x, int color)
{
	int	y_temp;
	int	x_temp;
	int	save_x;

	y_temp = y + 5;
	x_temp = x + 5;
	save_x = x;
	while (y < y_temp)
	{
		x = save_x;
		while (x < x_temp)
		{
			img_pix_put(&all->mini->img_mlx, x, y, color);
			x++;
		}
		y++;
	}
	return ;
}
