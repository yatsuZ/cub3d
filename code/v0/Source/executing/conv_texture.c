/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:02:25 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/15 15:15:03 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

int	convertion_image(t_all_data *all)
{
	if (all == NULL || all->img == NULL)
		return (1);
	all->img->width = 64;
	all->img->height = 64;
	all->file->img[NORTHH].image = mlx_xpm_file_to_image(all->mini->mlx, \
		all->textures->n_wall, &all->img->width, &all->img->height);
	if (!all->file->img[NORTHH].image)
		return (1);
	all->file->img[SOUTHH].image = mlx_xpm_file_to_image(all->mini->mlx, \
			all->textures->s_wall, &all->img->width, &all->img->height);
	if (!all->file->img[SOUTHH].image)
		return (1);
	all->file->img[WESTT].image = mlx_xpm_file_to_image(all->mini->mlx, \
			all->textures->w_wall, &all->img->width, &all->img->height);
	if (!all->file->img[WESTT].image)
		return (1);
	all->file->img[EASTT].image = mlx_xpm_file_to_image(all->mini->mlx, \
			all->textures->e_wall, &all->img->width, &all->img->height);
	if (!all->file->img[EASTT].image)
		return (1);
	if (get_adress_img(all))
		return (1);
	return (0);
}

int	get_adress_img(t_all_data *all)
{
	if (all == NULL || all->img == NULL)
		return (1);
	all->file->img[NORTHH].addr = mlx_get_data_addr(\
			all->file->img[NORTHH].image, &all->file->img[NORTHH].bitpp, \
			&all->file->img[NORTHH].line_length, &all->file->img[NORTHH].endian);
	if (!all->file->img[NORTHH].addr)
		return (1);
	all->file->img[SOUTHH].addr = mlx_get_data_addr(\
			all->file->img[SOUTHH].image, &all->file->img[SOUTHH].bitpp, \
			&all->file->img[SOUTHH].line_length, &all->file->img[SOUTHH].endian);
	if (!all->file->img[SOUTHH].addr)
		return (1);
	all->file->img[EASTT].addr = mlx_get_data_addr(\
			all->file->img[EASTT].image, &all->file->img[EASTT].bitpp, \
			&all->file->img[EASTT].line_length, &all->file->img[EASTT].endian);
	if (!all->file->img[EASTT].addr)
		return (1);
	all->file->img[WESTT].addr = mlx_get_data_addr(\
			all->file->img[WESTT].image, &all->file->img[WESTT].bitpp, \
			&all->file->img[WESTT].line_length, &all->file->img[WESTT].endian);
	if (!all->file->img[WESTT].addr)
		return (1);
	return (0);
}

void	free_image(t_all_data *all)
{
	if (!all->mini->mlx)
		return ;
	if (all->mini->img_mlx.image)
		mlx_destroy_image(all->mini->mlx, all->mini->img_mlx.image);
	if (all->file->img[NORTHH].image)
		mlx_destroy_image(all->mini->mlx, all->file->img[NORTHH].image);
	if (all->file->img[SOUTHH].image)
		mlx_destroy_image(all->mini->mlx, all->file->img[SOUTHH].image);
	if (all->file->img[WESTT].image)
		mlx_destroy_image(all->mini->mlx, all->file->img[WESTT].image);
	if (all->file->img[EASTT].image)
		mlx_destroy_image(all->mini->mlx, all->file->img[EASTT].image);
}
