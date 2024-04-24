/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:02:38 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/23 15:22:10 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

static bool	is_directory(char *file)
{
	int		fd;

	fd = open(file, O_DIRECTORY);
	if (fd >= 0)
		return (close (fd), true);
	return (false);
}

static bool	is_cub_file(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len > 4 && ft_strcmp(file + len - 4, ".cub", 4))
		return (true);
	return (false);
}

static bool	is_xpm_file(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len > 4 && ft_strcmp(file + len - 4, ".xpm", 4))
		return (true);
	return (false);
}

t_error_code	check_is_file_and_extension(char *arg, t_extension_file option)
{
	int	fd;

	if (is_directory(arg))
		return (ERR_IS_DIR);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (ERR_OPEN);
	close(fd);
	if (option == CUB && !is_cub_file(arg))
		return (ERR_INVALID_FILE);
	if (option == XPM && !is_xpm_file(arg))
		return (ERR_INVALID_FILE);
	return (ERR_NULL);
}
