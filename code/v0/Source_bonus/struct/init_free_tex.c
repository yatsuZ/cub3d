/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_tex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:29:17 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/15 17:19:37 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

int	init_tex(t_error_code *err, t_tex **tex)
{
	if (!err || *err != ERR_NULL)
		return (1);
	*tex = ft_calloc(1, sizeof(t_tex));
	if (!(*tex))
		return (*err = ERR_MALLOC, 1);
	ft_memset(*tex, 0, sizeof(t_tex));
	(*tex)->color = NULL;
	return (0);
}

void	free_tex(t_tex *tex)
{
	if (!tex)
		return ;
	free(tex);
}
