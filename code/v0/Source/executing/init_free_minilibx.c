/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_minilibx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:09:14 by lazanett          #+#    #+#             */
/*   Updated: 2024/03/22 17:17:21 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

int	init_minilibx(t_error_code *err, t_minilibx **mini)
{
	if (!err || !mini || *err != ERR_NULL)
		return (1);
	*mini = ft_calloc(1, sizeof(t_minilibx));
	if (!(*mini))
		return (*err = ERR_MALLOC, 1);
	return (0);
}

void	free_minilibx(t_minilibx **mini)
{
	if (!mini|| !*mini)
		return ;
	free(*mini);
}