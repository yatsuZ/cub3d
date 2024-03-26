/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:02:25 by lazanett          #+#    #+#             */
/*   Updated: 2024/03/26 11:01:48 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

t_error_code	convertion_image(t_all_data *all)
{
	ft_memset(all->img, 0, sizeof(t_img));
	if (all == NULL || all->img == NULL)
		return ERR_NULL;
	all->img->width = 64;
	all->img->height = 64;
	all->file->img[NORTH].image = mlx_xpm_file_to_image(all->mini->mlx, \
			all->textures->n_wall, &all->img->width, &all->img->height);
	if (!all->file->img[NORTH].image)
		return (free(all), all->err = ERR_XPM_TO_IMG);
	all->file->img[SOUTH].image = mlx_xpm_file_to_image(all->mini->mlx, \
			all->textures->s_wall,&all->img->width, &all->img->height);
	if (!all->file->img[SOUTH].image)
		return (free(all), all->err = ERR_XPM_TO_IMG);
	all->file->img[WEST].image = mlx_xpm_file_to_image(all->mini->mlx, \
			all->textures->n_wall, &all->img->width, &all->img->height);
	if (!all->file->img[WEST].image)
		return (free(all), all->err = ERR_XPM_TO_IMG);
	all->file->img[EAST].image = mlx_xpm_file_to_image(all->mini->mlx, \
			all->textures->n_wall, &all->img->width, &all->img->height);
	if (!all->file->img[EAST].image)
		return (free(all), all->err = ERR_XPM_TO_IMG);
	return (ERR_NULL);
}

void	free_image(t_all_data *all)
{
	if (all->file->img[NORTH].image)
		mlx_destroy_image(all->mini->mlx, all->file->img[NORTH].image);
	if (all->file->img[SOUTH].image)
		mlx_destroy_image(all->mini->mlx, all->file->img[SOUTH].image);
	if (all->file->img[WEST].image)
		mlx_destroy_image(all->mini->mlx, all->file->img[WEST].image);
	if (all->file->img[EAST].image)
		mlx_destroy_image(all->mini->mlx, all->file->img[EAST].image);
}
