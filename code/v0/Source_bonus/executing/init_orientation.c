/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_orientation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:11:18 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/17 15:19:06 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

int	init_orient(t_all_data *all)
{
	alloc_mapp(all);
	all->file->campos.x = all->world->spawn.y + 0.49f;
	all->file->campos.y = all->world->spawn.x + 0.49f;
	get_size_mapp(all);
	if (all->world->initial_angle == 87)
	{
		all->file->raydir.x = -1.0f;
		all->file->rayplane.y = -0.49f;
	}
	if (all->world->initial_angle == 69)
	{
		all->file->raydir.x = 1.0f;
		all->file->rayplane.y = 0.49f;
	}
	if (all->world->initial_angle == 83)
	{
		all->file->raydir.y = 1.0f;
		all->file->rayplane.x = -0.49f;
	}
	if (all->world->initial_angle == 78)
	{
		all->file->raydir.y = -1.0f;
		all->file->rayplane.x = 0.49f;
	}
	return (1);
}

void	get_size_mapp(t_all_data *all)
{
	int	i;
	int	j;
	int	size;
	
	i = all->fcb->start_map;
	size = 0;
	j = 0;
	all->file->nb_max_col = 0;
	all->file->nb_max_row = 0;
	while (i < all->fcb->nbr_line)
	{
		size = ft_strlen2(all->fcb->contained_by_line[i]);
		if (all->file->nb_max_row < size)
			all->file->nb_max_row = size;
		i++;
	}
	all->file->nb_max_col = all->fcb->nbr_line - all->fcb->start_map;
}
