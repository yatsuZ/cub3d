/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:36:51 by lazanett          #+#    #+#             */
/*   Updated: 2024/03/21 11:39:04 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

// static int	init_data_file(t_error_code *err, t_data_file *file)
// {
// 	if (!err || !file || *err != ERR_NULL)
// 		return (1);
// 	file = ft_calloc(0, sizeof(t_data_file));
// 	if (!file)
// 		return (*err = ERR_MALLOC, 1);
// 	return (printf("coucou\n"));
// }
// void	start_exec(t_all_data *all)
// {
// 	init_data_file(&all->err, all->file);
// 	all->file->mlx = mlx_init();
// 	if (all->file->mlx == NULL)
// 		return ;
// 	all->file->win = mlx_new_window(all->file->mlx, 1000, 1000, "Game");
// 	// tab_img(&elem);
// 	// mlx_hook(all->file->window, KeyPress, 1L << 0, ft_key, &elem);
// 	// mlx_hook(all->file->window, ClientMessage, 1L << 5, ft_mouse, 
// 	//&elem);
// 	mlx_loop(all->file->mlx);
// }


static int	init_data_file(t_error_code *err, t_data_file **file)
{
	if (!err || !file || *err != ERR_NULL)
		return (1);
	*file = ft_calloc(1, sizeof(t_data_file));
	if (!(*file))
		return (*err = ERR_MALLOC, 1);
	return (printf("coucou\n"));
}
void	start_exec(t_all_data **all) {

	init_data_file(&(*all)->err, &(*all)->file);
	(*all)->file->mlx = mlx_init();
	if ((*all)->file->mlx == NULL)
		return ;
	(*all)->file->win = mlx_new_window((*all)->file->mlx, 1000, 1000, "Game");
	// tab_img(&elem);
	// mlx_hook(all->file->window, KeyPress, 1L << 0, ft_key, &elem);
	// mlx_hook(all->file->window, ClientMessage, 1L << 5, ft_mouse, 
	//&elem);
	mlx_loop((*all)->file->mlx);
}