/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:04:38 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/08 17:13:46 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

void	raycasting(t_all_data *all)
{
	int i;

	i = 0;
	while (i < all->mini->sizex)
	{
		init_dda(all, i);
		calcul_delta(all);
		perform_dda(all);
		handle_no_colision(all);
		limit_wall_height(all);
		draw_wall(all, i);
		i++;
	}
	// printf("map %f | %f\n", all->file->map.x, all->file->map.y);
	// printf("campos %f | %f\n", all->file->campos.x, all->file->campos.y);
	// printf("raydir %f | %f\n", all->file->raydir.x, all->file->raydir.y);
	// printf("dir %f | %f\n", all->file->dir.x, all->file->dir.y);
	// printf("deltadist %f | %f\n", all->file->delta.x, all->file->delta.y);
	// printf("sidedist %f | %f\n", all->file->sidedist.x, all->file->sidedist.y);
	mlx_put_image_to_window(all->mini->mlx, all->mini->win, \
		all->mini->img_mlx.image, 0, 0);
}

float	conv_neg(float n)
{
	if (n < 0)
		n *= -1;
	return (n);
}
