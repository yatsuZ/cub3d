/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:35:58 by lazanett          #+#    #+#             */
/*   Updated: 2024/03/22 12:40:53 by lazanett         ###   ########.fr       */
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

// int	key_press(int keycode, t_all_data *all)
// {
// 	(void)all;
// 	if (keycode == XK_Up || keycode == XK_w)
// 		// all->file->up = 1;
// 		//printf("up");
// 	if (keycode == XK_Down || keycode == XK_s)
// 		// all->file->down = 1;
// 		//printf("bas");
// 	if (keycode == XK_a || keycode == XK_Left)
// 		// all->file->left = 1;
// 		//printf("left");
// 	if (keycode == XK_d || keycode == XK_Right)
// 		// all->file->right = 1;
// 		//printf("droite");
// 	if (keycode == XK_Escape)
// 		// all->file->esc = 1;
// 	{
// 		printf("Esc");
// 		exit(0);
// 	}
// 	return (0);
// }

int	key_drop(int keycode, t_all_data *all)
{
	(void)all;
	if (keycode == XK_Up || keycode == XK_w)
		// all->file->up = 0;
		printf("up");
	if (keycode == XK_Down || keycode == XK_s)
		// all->file->down = 0;
		printf("bas");
	if (keycode == XK_a || keycode == XK_Left)
		// all->file->left = 0;
		printf("left");
	if (keycode == XK_d || keycode == XK_Right)
		// all->file->right = 0;
		printf("droite");
	if (keycode == XK_Escape)
		// all->file->esc = 0;
		exit(0);
	return (0);
}

int	escape(t_all_data *all)
{
	(void) all;
	// end(all);
	exit(0);
}