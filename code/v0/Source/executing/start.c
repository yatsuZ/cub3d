/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:36:51 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/05 13:12:47 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

t_error_code	start_exec(t_all_data *all)
{
	printf("%ld   |   %ld\n", all->world->spawn.x, all->world->spawn.y);
	all->mini->mlx = mlx_init();
	if (all->mini->mlx == NULL)
		return  ERR_INIT_LIBX;
	if (!init_orient(all))
		return ERR_TEX;
	if (convertion_image(all))
		return ERR_XPM_TO_IMG;
	screen_size(all);
	all->mini->win = mlx_new_window(all->mini->mlx, all->mini->sizex, all->mini->sizey, "Cub3D");
	if (all->mini->win == NULL)
		return ERR_WIN_LIBX;
	all->mini->img_mlx.image = mlx_new_image(all->mini->mlx, all->mini->sizex, \
				all->mini->sizey);
	if (!(all->mini->img_mlx.image))
		return ERR_WIN_LIBX;
	all->mini->img_mlx.addr = mlx_get_data_addr(all->mini->img_mlx.image, \
		&all->mini->img_mlx.bitpp, &all->mini->img_mlx.line_length, \
		&all->mini->img_mlx.endian);
	if (!(all->mini->img_mlx.addr))
		return ERR_WIN_LIBX;
	mlx_loop_hook(all->mini->mlx, ft_game, all);
	mlx_hook(all->mini->win, 2, KeyPressMask, &key_press, all->file);
	mlx_hook(all->mini->win, 3, KeyReleaseMask, &key_drop, all->file);
	mlx_hook(all->mini->win, ClientMessage, 1L << 5, escape, all->file);
	mlx_loop(all->mini->mlx);
	return ERR_NULL;
}

int	ft_game(t_all_data *all)
{
	ft_key(all);
	draw_void(all);
	raycasting(all);
	return (0);
}

void	screen_size(t_all_data *all)
{
	int	screen_width;
	int	screen_height;

	mlx_get_screen_size(all->mini->mlx, &screen_width, &screen_height);
	if (screen_width >= 1920)
		all->mini->sizex = 1920;
	else
		all->mini->sizex  = 848;
	if (screen_height >= 1080)
		all->mini->sizey = 1080;
	else
		all->mini->sizey = 480;
}
