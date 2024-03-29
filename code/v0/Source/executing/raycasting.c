/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:04:38 by lazanett          #+#    #+#             */
/*   Updated: 2024/03/28 15:28:31 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

void	raycasting(t_all_data *all)
{
	int i;

	i = 0;
	while (i < all->mini->sizex)// calcul des distances aux murs et dessiner les bandes verticale
	{
		init_dda(all, i);
		calcul_delta(all);
		perform_dda(all);
		handle_no_colision(all);
		limit_wall_height(all);
		i++;
	}
}

double	conv_neg(double n)
{
	if (n < 0)
		n *= -1;
	return (n);
}