/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:36:51 by lazanett          #+#    #+#             */
/*   Updated: 2024/03/21 18:49:30 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

t_error_code	start_exec(t_all_data **all) {

	init_data_file(&(*all)->err, &(*all)->file);
	(*all)->file->mlx = mlx_init();
	if ((*all)->file->mlx == NULL)
		return  ERR_INIT_LIBX;
	screen_size(*all);
	(*all)->file->win = mlx_new_window((*all)->file->mlx, (*all)->file->sizex, (*all)->file->sizey, "Cub3D");
	if ((*all)->file->win == NULL)
		return ERR_WIN_LIBX;
	mlx_hook((*all)->file->win, 2, KeyPressMask, &key_press, (*all)->file);
	mlx_hook((*all)->file->win, 3, KeyReleaseMask, &key_drop, (*all)->file);
	mlx_hook((*all)->file->win, ClientMessage, 1L << 5, escape, (*all)->file);
	mlx_loop((*all)->file->mlx);
	return ERR_NULL;
}

void	screen_size(t_all_data *all)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(all->file->mlx, &screen_width, &screen_height);
	if (screen_width >= 1920)
		all->file->sizex = 1920;
	else
		all->file->sizex  = 848;
	if (screen_height >= 1080)
		all->file->sizey = 1080;
	else
		all->file->sizey = 480;
}
