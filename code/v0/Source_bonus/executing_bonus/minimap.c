/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:56:06 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/19 17:01:23 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

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
			else if (y == (int)all->file->campos.y && x == (int)all->file->campos.x)
				draw_square(all, current_y_bis, all->file->bis.x, 0xF11818);
			else if (cell == '0' || is_dir(cell))
				draw_square(all, current_y_bis, all->file->bis.x, 0xFFF7F7);
			else if (cell == '2')
				draw_square(all, current_y_bis, all->file->bis.x, 0xFFE4B5);
			x++;
			all->file->bis.x += 5;
		}
		current_y_bis += 5;
		y++;
	}
}

// void	draw_minimap(t_cellule *c)
// {
	
// }
// void	show_element_minimap(t_element_map em)
// {
// 	if (em == UNKNOW)
// 		printf("?");
// 	else if (em == VOID)
// 	{
// 		put_color_txt(BLEU);
// 		printf("V");
// 	}
// 	else if (em == WALL)
// 	{
// 		put_color_txt(ROUGE);
// 		printf("M");
// 	}
// 	else if (em >= SPAWN_N && em <= SPAWN_W)
// 	{
// 		put_color_txt(JAUNE);
// 		printf("S");
// 	}
// 	else if (em == FLOOR_E)
// 	{
// 		put_color_txt(VERT);
// 		printf("F");
// 	}
// 	put_color_txt(EMPTY_COLOR);
// }

// void	show_minimap(t_cellule *c)
// {
// 	if (!c)
// 		return ;
// 	show_element(c->element);
// 	show_map_2d(c->east);
// 	if (c->east == NULL)
// 		printf("\n");
// 	if (c->west == NULL)
// 		show_map_2d(c->south);
// }