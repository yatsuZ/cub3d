/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:56:47 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/22 13:15:44 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	init_minimap(t_all_data *all)
{
	all->file->perimeter_size = 20;
	all->file->start.x = max(0, all->file->campos.x - all->file->perimeter_size \
		/ 2);
	all->file->start.y = max(0, all->file->campos.y - all->file->perimeter_size \
		/ 2);
	all->file->end.x = min(all->file->nb_max_row, all->file->start.x + \
		all->file->perimeter_size);
	all->file->end.y = min(all->file->nb_max_col, all->file->start.y + \
		all->file->perimeter_size);
	all->file->bis.x = 0;
	all->file->bis.y = 0;
}
