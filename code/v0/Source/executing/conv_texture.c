/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:02:25 by lazanett          #+#    #+#             */
/*   Updated: 2024/03/26 13:45:49 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

int	convertion_image(t_all_data *all)
{
	ft_memset(all->img, 0, sizeof(t_img));
	if (all == NULL || all->img == NULL)
		return (1);
	all->img->width = 64;
	all->img->height = 64;
	all->file->img[NORTH].image = mlx_xpm_file_to_image(all->mini->mlx, \
			all->textures->n_wall, &all->img->width, &all->img->height);
	if (!all->file->img[NORTH].image)
		return (1);
	all->file->img[SOUTH].image = mlx_xpm_file_to_image(all->mini->mlx, \
			all->textures->s_wall,&all->img->width, &all->img->height);
	if (!all->file->img[SOUTH].image)
		return (1);
	all->file->img[WEST].image = mlx_xpm_file_to_image(all->mini->mlx, \
			all->textures->n_wall, &all->img->width, &all->img->height);
	if (!all->file->img[WEST].image)
		return (1);
	all->file->img[EAST].image = mlx_xpm_file_to_image(all->mini->mlx, \
			all->textures->n_wall, &all->img->width, &all->img->height);
	if (!all->file->img[EAST].image)
		return (1);
	if (get_adress_img(all))
		return (1);
	return (0);
}

int	get_adress_img(t_all_data *all)
{
	if (all == NULL || all->img == NULL)
		return (1);
	all->file->img[NORTH].addr = mlx_get_data_addr(\
			all->file->img[NORTH].image, &all->file->img[NORTH].bitpp, \
			&all->file->img[NORTH].line_length, &all->file->img[NORTH].endian);
	if (!all->file->img[NORTH].addr)
		return (1);
	all->file->img[SOUTH].addr = mlx_get_data_addr(\
			all->file->img[SOUTH].image, &all->file->img[SOUTH].bitpp, \
			&all->file->img[SOUTH].line_length, &all->file->img[SOUTH].endian);
	if (!all->file->img[SOUTH].addr)
		return (1);
	all->file->img[EAST].addr = mlx_get_data_addr(\
			all->file->img[EAST].image, &all->file->img[EAST].bitpp, \
			&all->file->img[EAST].line_length, &all->file->img[EAST].endian);
	if (!all->file->img[EAST].addr)
		return (1);
	all->file->img[WEST].addr = mlx_get_data_addr(\
			all->file->img[WEST].image, &all->file->img[WEST].bitpp, \
			&all->file->img[WEST].line_length, &all->file->img[WEST].endian);
	if (!all->file->img[WEST].addr)
		return (1);
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + ((y * img->line_length) + (x * (img->bitpp / 8)));
	*(int *)pixel = color;
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
