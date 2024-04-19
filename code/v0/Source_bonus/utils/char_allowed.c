/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_allowed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:06:01 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/19 16:03:19 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

bool	char_allowed(char c)
{
	return (((c == ' ') || (c == '0') || (c == '1') || \
	(c == 'N') || (c == 'S') || (c == 'E') || (c == 'W') || (c == '\n')));
}

size_t	ft_strlen2(const char *cha)
{
	size_t	i;

	i = 0;
	while (cha[i] != '\0' && cha[i] != '\n')
		i++;
	return (i);
}
