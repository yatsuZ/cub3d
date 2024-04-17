/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:48:42 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/16 14:46:41 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

char	*ft_replace(char *str, char to_replace, char c)
{
	char	*res;
	int		i;

	res = ft_strdup(str);
	if (!res)
		return (NULL);
	i = 0;
	while (res[i])
	{
		if (res[i] == to_replace)
			res[i] = c;
		i++;
	}
	return (res);
}

bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

bool	is_number_array(char **tab, int i)
{
	int		j;
	bool	chiffre;

	while (tab[i])
	{
		j = 0;
		chiffre = false;
		while (tab[i][j] && !(chiffre == true && tab[i][j] <= 32))
		{
			if (!ft_isdigit(tab[i][j]) && tab[i][j] > 32)
				return (false);
			if (ft_isdigit(tab[i][j]))
				chiffre = true;
			j++;
		}
		while (tab[i][j])
		{
			if (tab[i][j] > 32)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	size_path(char *line)
{
	int	res;

	res = 0;
	while (line[res] > 32)
		res++;
	return (res);
}

int	size_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (i);
	while (tab[i])
		i++;
	return (i);
}
