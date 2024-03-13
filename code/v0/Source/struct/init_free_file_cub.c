/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_file_cub.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:42:09 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/13 17:13:49 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

static int	get_content(t_file_cub *fcb, t_error_code *err)
{
	char	*line;
	int		i;

	if (!fcb || !err || *err != ERR_NULL)
		return (1);
	fcb->fd = open(fcb->path, O_RDONLY);
	if (fcb->fd < 0)
		return (*err = ERR_OPEN, 1);
	line = get_next_line(fcb->fd, 0);
	i = 0;
	while (line != NULL)
	{
		fcb->contained_by_line[i] = ft_strdup(line);
		if (!fcb->contained_by_line[i++])
		{
			free(line);
			get_next_line(fcb->fd, 1);
			return (close(fcb->fd), *err = ERR_MALLOC, 1);
		}
		free(line);
		line = get_next_line(fcb->fd, 0);
	}
	return (get_next_line(fcb->fd, 1), close(fcb->fd), 0);
}

static int	nbr_line_file(char *file, t_error_code *err)
{
	int		fd;
	char	*line;
	int		res;

	if (*err != ERR_NULL)
		return (-1);
	res = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (*err = ERR_OPEN, -1);
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		free(line);
		if (res == __INT_MAX__)
		{
			*err = ERR_TO_MUCH_LINE;
			return (get_next_line(fd, 1), close(fd), -1);
		}
		res++;
		line = get_next_line(fd, 0);
	}
	close(fd);
	return (res);
}

int	init_file_cub(char *path, t_error_code *err, t_file_cub **fcb)
{
	if (!path || !err || !fcb || *err != ERR_NULL)
		return (1);
	*fcb = ft_calloc(1, sizeof(t_file_cub));
	if (!(*fcb))
		return (*err = ERR_MALLOC, 1);
	(*fcb)->start_map = -1;
	(*fcb)->path = path;
	*err = check_is_file_and_extension(path, CUB);
	(*fcb)->nbr_line = nbr_line_file(path, err);
	if (*err != ERR_NULL)
		return ((*fcb)->contained_by_line = NULL, 1);
	(*fcb)->contained_by_line = ft_calloc((*fcb)->nbr_line + 1, sizeof(char *));
	if ((*fcb)->contained_by_line == NULL)
		return (*err = ERR_MALLOC, 1);
	return (get_content(*fcb, err));
}

void	free_tab_char(char **tableau, int len)
{
	int	i;

	i = 0;
	if (!tableau)
		return ;
	while ((len != -1 && i < len) || tableau[i])
	{
		free(tableau[i]);
		tableau[i] = NULL;
		i++;
	}
	free(tableau);
	tableau = NULL;
}

void	free_file_cub(t_file_cub **fcb)
{
	if (!fcb || !*fcb)
		return ;
	free_tab_char((*fcb)->contained_by_line, (*fcb)->nbr_line);
	(*fcb)->contained_by_line = NULL;
	(*fcb)->path = NULL;
	free(*fcb);
	*fcb = NULL;
}
