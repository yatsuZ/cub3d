/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:40:23 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/16 14:45:29 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d_bonus.h"

void	show_file_cub(t_file_cub *fcb)
{
	int	i;

	printf("Adresse du file cub structure:\t");
	put_color_txt(JAUNE);
	printf("%p\n", fcb);
	put_color_txt(EMPTY_COLOR);
	if (!fcb)
		return ;
	printf("Chemin du fichier:\t");
	put_color_txt(VERT);
	printf("%s\n", fcb->path);
	put_color_txt(EMPTY_COLOR);
	i = 0;
	while (fcb->contained_by_line && fcb->contained_by_line[i])
	{
		put_color_txt(BLEU);
		printf("%d\t|", i);
		put_color_txt(EMPTY_COLOR);
		printf("%s\n", fcb->contained_by_line[i++]);
	}
	put_color_txt(ROUGE);
	printf("\n\nadresse du tableau = %p\n", fcb->contained_by_line);
	put_color_txt(EMPTY_COLOR);
}
