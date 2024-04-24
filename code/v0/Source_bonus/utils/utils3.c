/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:09:51 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/23 14:47:21 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

int	ft_atoi(const char *nptr)
{
	long	nbr;
	int		signe;
	size_t	i;

	i = 0;
	nbr = 0;
	signe = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		i++;
		signe = -1;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10;
		nbr += nptr[i] - '0';
		if (nbr > 2147483647 || nbr * signe < -2147483648)
			return (-1);
		i++;
	}
	return ((int)(signe * nbr));
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (src[i] && (size > 0 && i < (size - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
	{
		dest[i++] = '\0';
	}
	return (ft_strlen((char *)src));
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *) s;
	len = ft_strlen(str) + 1;
	ptr = ft_calloc(len, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str, len);
	return (ptr);
}

int	ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	lon;
	char	*news;
	size_t	space;

	if (!s)
		return (NULL);
	lon = ft_strlen((char *) s);
	if (start > lon)
		return (ft_strdup(""));
	space = lon - start ;
	if (space > len)
		space = len;
	news = ft_calloc(space + 1, sizeof(char));
	i = 0;
	while (news && s[i + start] && i < len)
	{
		news[i] = s[i + start];
		i++;
	}
	if (news && news[i])
		news[i] = '\0';
	return (news);
}
