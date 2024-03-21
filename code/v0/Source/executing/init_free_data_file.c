/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_data_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:38:06 by lazanett          #+#    #+#             */
/*   Updated: 2024/03/21 18:16:23 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

int	init_data_file(t_error_code *err, t_data_file **file)
{
	if (!err || !file || *err != ERR_NULL)
		return (1);
	*file = ft_calloc(1, sizeof(t_data_file));
	if (!(*file))
		return (*err = ERR_MALLOC, 1);
	return (0);
}

void	free_data_file(t_data_file **file)
{
	if (!file|| !*file)
		return ;
	free(*file);
}