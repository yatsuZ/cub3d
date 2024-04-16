/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:08:06 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/15 17:10:24 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

void	draw_wall(t_all_data *all, int j)
{
	t_tex	texture;
	int		i;

	texture = init_draw_wall(all);
	i = all->file->drawstart;
	while (i < all->file->drawend)
	{
		texture.texty = (int)texture.textpos & (all->img->height - 1);
		texture.textpos += texture.textstep;
		texture.color = texture.texture.addr + (int)(texture.texty * \
		texture.texture.line_length + texture.textx * \
		(texture.texture.bitpp / 8));
		img_pix_put(&all->mini->img_mlx, j, i, *(int *)texture.color);
		i++;
	}
}

t_tex	init_draw_wall(t_all_data *all)
{
	t_tex	texture;

	texture.texture = get_texture_tab(all);
	texture.wall_x = get_wallx(all);
	texture.texture.width = 64;
	texture.texture.height = 64;
	texture.textx = (int)(texture.wall_x * texture.texture.width);
	if (all->file->side == 1 || all->file->side == 2)
		texture.textx = texture.texture.width - texture.textx - 1;
	texture.textstep = 1.0 * texture.texture.height / all->file->line_height;
	texture.textpos = (all->file->drawstart - all->mini->sizey / 2 + \
	all->file->line_height / 2) * texture.textstep;
	texture.color = NULL;
	return (texture);
}

double	get_wallx(t_all_data *all)
{
	double	wallx;

	if (all->file->side == 0)
		wallx = all->file->campos.y + all->file->distwall \
		* all->file->dir.y;
	else
		wallx = all->file->campos.x + all->file->distwall \
		* all->file->dir.x;
	wallx -= floor(wallx);
	if ((all->file->side == 0 && all->file->dir.x < 0) \
	|| (all->file->side == 1 && all->file->dir.y < 0))
		wallx = 1.0f - wallx;
	return (wallx);
}

void	draw_void(t_all_data *all)
{
	int	i;
	int	j;

	i = -1;
	while (++i < all->mini->sizex)
	{
		j = -1;
		while (++j < all->mini->sizey / 2)
			img_pix_put(&all->mini->img_mlx, i, j, \
			*all->textures->ceiling_color);
		while (++j < all->mini->sizey)
			img_pix_put(&all->mini->img_mlx, i, j, *all->textures->floor_color);
	}
}
