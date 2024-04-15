/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_data_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:38:06 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/15 14:56:31 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

int	init_data_file(t_error_code *err, t_data_file **file)
{
	if (!err || *err != ERR_NULL)
		return (1);
	*file = ft_calloc(1, sizeof(t_data_file));
	if (!(*file))
		return (*err = ERR_MALLOC, 1);

	return (0);
}

static	void	ft_free(char **free_me)
{
	int		i;

	i = 0;
	if (!free_me)
		return ;
	while (free_me[i])
	{
		free(free_me[i]);
		i++;
	}
	free(free_me);
}

void	free_data_file(t_all_data *all)
{
	if (!all->file)
		return ;
	ft_free(all->file->mapp);
	free(all->file);
}

t_error_code	alloc_mapp(t_all_data *all)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = all->fcb->nbr_line - all->fcb->start_map;
	if (all->fcb->nbr_line - all->fcb->start_map <= 0)
		return ERR_SIZE_MALLOC;
	all->file->mapp = malloc(sizeof (char *) * (size + 1));
	if (!all->file->mapp)
		return ERR_MALLOC;
	while (i < size + 1)
		all->file->mapp[i++] = NULL;
	i = all->fcb->start_map;
	while (i < all->fcb->nbr_line)
	{
		all->file->mapp[j] = ft_strdup(all->fcb->contained_by_line[i]);
		i++;
		j++;
	}
	all->file->mapp[j] = NULL;
	return ERR_NULL;
}
