/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:17:06 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/15 17:17:17 by lazanett         ###   ########.fr       */
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
	ft_memset(*img, 0, sizeof(t_img));
	(*img)->image = NULL;
	(*img)->addr = NULL;
	return (0);
}

void	free_img(t_img *img)
{
	if (!img)
		return ;
	free(img);
}
