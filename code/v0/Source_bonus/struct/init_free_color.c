/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:03:19 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/16 14:45:57 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

int	init_color(t_error_code *err, t_color **rgb)
{
	if (!err || *err != ERR_NULL)
		return (1);
	*rgb = ft_calloc(1, sizeof(t_color));
	if (!(*rgb))
		return (*err = ERR_MALLOC, 1);
	ft_memset(*rgb, 0, sizeof(t_color));
	return (0);
}

void	free_color(t_color *rgb)
{
	if (!rgb)
		return ;
	free(rgb);
}