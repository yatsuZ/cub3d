/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_data_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:38:06 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/05 15:33:10 by lazanett         ###   ########.fr       */
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
	//ft_memset(&file, 0, sizeof(t_data_file));
	return (0);
}

void	free_data_file(t_all_data *all)
{
	if (!all->file)
		return ;
	free_tab_char(all->file->mapp, (all->fcb->nbr_line - all->fcb->start_map + 1));
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
		all->file->mapp[j] = all->fcb->contained_by_line[i];
		//printf("%s", all->file->mapp[j]);
		i++;
		j++;
	}
	all->file->mapp[j] = NULL;
	return ERR_NULL;
}
