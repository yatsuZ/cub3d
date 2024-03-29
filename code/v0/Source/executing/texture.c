/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:16:22 by lazanett          #+#    #+#             */
/*   Updated: 2024/03/28 16:52:34 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

t_img	get_texture(t_all_data *all)
{
	if (all->file->side == 0)
	{
		if (all->file->dir.x > 0.f)
			return (all->file->img[NORTH]);
		else
			return (all->file->img[SOUTH]);
	}
	else
	{
		if (all->file->dir.y > 0.f)
			return (all->file->img[EAST]);
		else
			return (all->file->img[WEST]);
	}
}

