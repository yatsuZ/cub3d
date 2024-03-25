/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:35:58 by lazanett          #+#    #+#             */
/*   Updated: 2024/03/25 14:18:42 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./../../Header/cub3d.h"

int	ft_key(int keycode, t_all_data *all)
{
	(void) all;
	if (keycode == XK_Escape)
	{
		//end(all);
		exit(0);
	}
	// if (keycode == XK_Up || keycode == XK_w)
	// 	//move_up(nb);
	// else if (keycode == XK_Left || keycode == XK_a)
	// 	//move_left(nb);
	// else if (keycode == XK_Right || keycode == XK_d)
	// 	//move_right(nb);
	// else if (keycode == XK_Down || keycode == XK_s)
	// 	//move_down(nb);
	return (0);
}

int	key_press(int keycode, t_data_file *file)
{
	if (!file)
		return (1);
	if (keycode == XK_Up || keycode == XK_w)
		file->up = 1;
	if (keycode == XK_Down || keycode == XK_s)
		file->down = 1;
	if (keycode == XK_a || keycode == XK_Left)
		file->left = 1;
	if (keycode == XK_d || keycode == XK_Right)
		file->right = 1;
	if (keycode == XK_Escape)
	{
		file->esc = 1;
		exit(0);
	}
	return (0);
}

int	key_drop(int keycode, t_data_file *file)
{
	if (!file)
		return (1);
	if (keycode == XK_Up || keycode == XK_w)
		file->up = 0;
	if (keycode == XK_Down || keycode == XK_s)
		file->down = 0;
	if (keycode == XK_a || keycode == XK_Left)
		file->left = 0;
	if (keycode == XK_d || keycode == XK_Right)
		file->right = 0;
	if (keycode == XK_Escape)
		file->esc = 0;
	return (0);
}

int	escape(t_all_data *all)
{
	(void) all;
	// end(all);
	exit(0);
}