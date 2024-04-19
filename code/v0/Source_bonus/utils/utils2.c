/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:48:54 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/19 15:10:05 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

int	skip_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	return (i);
}

bool	is_a_legit_line_map(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (char_allowed(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

size_t	ft_strlen(const char *cha)
{
	size_t	i;

	i = 0;
	while (cha[i] != '\0')
		i++;
	return (i);
}

bool	ft_strcmp(char *s1, char *s2, long size)
{
	long	i;

	i = 0;
	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2)
		return (false);
	while (s1[i] && s2[i] && (size > 0 && i < size))
	{
		if (s1[i] != s2[i])
			return (false);
		i++;
	}
	if ((size > 0 && i < size) && s1[i] != s2[i])
		return (false);
	return (true);
}

t_element_map	define_element(char c)
{
	if (c == ' ' || c == '\n')
		return (VOID);
	else if (c == '0')
		return (FLOOR_E);
	else if (c == '1')
		return (WALL);
	else if (c == 'N')
		return (SPAWN_N);
	else if (c == 'S')
		return (SPAWN_S);
	else if (c == 'E')
		return (SPAWN_E);
	else if (c == 'W')
		return (SPAWN_W);
	return (UNKNOW);
}
