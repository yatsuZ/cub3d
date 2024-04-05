/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_minilibx.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:09:14 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/05 13:38:25 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

int	init_minilibx(t_error_code *err, t_minilibx **mini)
{
	if (!err || !mini || *err != ERR_NULL)
		return (1);
	*mini = ft_calloc(1, sizeof(t_minilibx));
	if (!(*mini))
		return (*err = ERR_MALLOC, 1);
	//ft_memset(&mini, 0, sizeof(t_minilibx));
	return (0);
}

void	free_minilibx(t_all_data *all, t_minilibx **mini)
{
	if (!mini|| !*mini || !all)
		return ;
	free_image(all);
	if ((*mini)->win)
	{
		mlx_clear_window((*mini)->mlx, (*mini)->win);
		mlx_destroy_window((*mini)->mlx, (*mini)->win);
	}
	if ((*mini)->mlx)
	{
		mlx_destroy_display((*mini)->mlx);
		free((*mini)->mlx);
		(*mini)->mlx = NULL;
	}	
	free(*mini);
	mini = NULL;
}