/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:17:06 by lazanett          #+#    #+#             */
/*   Updated: 2024/03/25 17:18:39 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

int	init_img(t_error_code *err, t_img **img)
{
	if (!err || *err != ERR_NULL)
		return (1);
	*img = ft_calloc(1, sizeof(t_img));
	if (!(*img))
		return (*err = ERR_MALLOC, 1);
	return (0);
}

void	free_img(t_img *img)
{
	if (!img)
		return ;
	free(img);
}