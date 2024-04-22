/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:56:06 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/22 13:27:41 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

static int	linelen(char *line);

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

void	draw_minimap(t_all_data *all, int y, int x)
{
	char	cell;

	init_minimap(all);
	y = all->file->start.y;
	while (y < all->file->end.y)
	{
		all->file->bis.x = 0;
		x = all->file->start.x;
		while (x < linelen(all->file->mapp[y]) && x < all->file->end.x)
		{
			cell = all->file->mapp[y][x];
			if (cell == '1')
				draw_square(all, all->file->bis.y, all->file->bis.x, 0xACAAA8);
			else if (y == (int)all->file->campos.y && \
				x == (int)all->file->campos.x)
				draw_square(all, all->file->bis.y, all->file->bis.x, 0xF11818);
			else if (cell == '0' || is_dir(cell))
				draw_square(all, all->file->bis.y, all->file->bis.x, 0xFFF7F7);
			x++;
			all->file->bis.x += 5;
		}
		all->file->bis.y += 5;
		y++;
	}
}

int	linelen(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}
