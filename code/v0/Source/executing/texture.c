/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:16:22 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/08 18:13:19 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

t_img	get_texture_tab(t_all_data *all)
{
	if (all->file->side == 0)
	{
		if (all->file->dir.x > 0.f)
			return (all->file->img[NORTHH]);
		else
			return (all->file->img[SOUTHH]);
	}
	else
	{
		if (all->file->dir.y > 0.f)
			return (all->file->img[EASTT]);
		else
			return (all->file->img[WESTT]);
	}
}

void	img_pix_put(t_img *img, int x, int y, unsigned long color)
{
	char	*pixel;

	pixel = img->addr + ((y * img->line_length) + (x * (img->bitpp / 8)));
	*(int *)pixel = color;
}


