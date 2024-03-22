/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:31:28 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/22 11:36:20 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

int	init_all(t_all_data **all, char *path_file)
{
	*all = ft_calloc(1, sizeof(t_all_data));
	if (!(*all))
		return (EXIT_FAILURE);
	(*all)->err = ERR_NULL;
	init_file_cub(path_file, &(*all)->err, &(*all)->fcb);
	init_all_texture((*all)->fcb, &(*all)->err, &(*all)->textures);
	if ((*all)->err == ERR_NULL && (*all)->fcb && (*all)->fcb->start_map < 0)
		(*all)->err = ERR_MISSING_MAP;
	init_world((*all)->fcb, &(*all)->err, &(*all)->world);
	return (!((*all)->err == ERR_NULL));
}

void	free_all(t_all_data **all)
{
	if (!all || !(*all))
		return ;
	free_world(&(*all)->world);
	free_all_texture(&(*all)->textures);
	free_file_cub(&((*all)->fcb));
	free_data_file(&(*all)->file);
	free(*all);
	*all = NULL;
}
