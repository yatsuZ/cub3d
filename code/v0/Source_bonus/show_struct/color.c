/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:39:56 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/16 14:45:19 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

void	put_color_txt(t_color_texte color)
{
	if (color == ROUGE)
		printf("\033[31m");
	else if (color == VERT)
		printf("\033[32m");
	else if (color == JAUNE)
		printf("\033[33m");
	else if (color == BLEU)
		printf("\033[34m");
	else if (color == MAGENTA)
		printf("\033[35m");
	else if (color == CYAN)
		printf("\033[36m");
	else if (color == BLANC)
		printf("\033[37m");
	else
		printf("\033[0m");
}
