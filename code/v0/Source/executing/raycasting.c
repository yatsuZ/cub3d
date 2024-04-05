/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:04:38 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/05 15:33:20 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

void	raycasting(t_all_data *all)
{
	int i;

	i = 0;
	//printf("---%f | %f\n", all->file->campos.x, all->file->campos.y);
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
	mlx_put_image_to_window(all->mini->mlx, all->mini->win, \
		all->mini->img_mlx.image, 0, 0);
}

double	conv_neg(double n)
{
	if (n < 0)
		n *= -1;
	return (n);
}