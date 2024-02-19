/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:48:54 by yzaoui            #+#    #+#             */
/*   Updated: 2024/02/19 23:08:34 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

int	skip_white_space(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] <= 32)
		i++;
	return (i);
}

bool	char_allowed(char c)
{
	return (c == ' ' || c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '\n');
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

bool	ft_strcmp(char *s1, char *s2)
{
	long	i;

	i = 0;
	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2)
		return (false);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (false);
		i++;
	}
	if (s1[i] != s2[i])
		return (false);
	return (true);
}
