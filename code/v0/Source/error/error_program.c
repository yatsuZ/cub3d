/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:57:37 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/15 16:22:44 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

static void	show_end2(t_error_code err)
{
	if (err == ERR_BAD_SYNTAXE_MAP)
		printf("Invalid syntax for MAP.\n");
	else if (err == ERR_REDUNDANCE_SPAWN)
		printf("Multiple spawn in map.\n");
	else if (err == ERR_MISSING_SPAWN)
		printf("MISSING SPAWN in map !\n");
	else if (err == ERR_WALL_NOT_CLOSE)
		printf("MAP NOT CLOSE BY WALL !\n");
	else if (err == ERR_INIT_LIBX)
		printf("Minilibx init failed\n");
	else if (err ==	ERR_WIN_LIBX)
		printf("Minilibx window failed\n");
	else if (err == ERR_XPM_TO_IMG)
		printf("Invalid image\n");
	else if (err == ERR_TEX)
		printf("Invalid texture\n");
	else if (err == ERR_SIZE_MALLOC)
		printf("Size malloc invalid\n");
}

void	show_end(t_error_code err)
{
	if (err == ERR_NULL)
		return ;
	printf("Error:\n");
	if (err == ERR_MALLOC)
		printf("Malloc Fail.\n");
	else if (err == ERR_UNKNOW)
		printf("?? ??.\n");
	else if (err == ERR_IS_DIR)
		printf("File is a directory.\n");
	else if (err == ERR_OPEN)
		perror("");
	else if (err == ERR_INVALID_FILE)
		printf("Invalid file format.\n");
	else if (err == ERR_TO_MUCH_LINE)
		printf("OVERFLOW: To much line into \"[file].cub\" .\n");
	else if (err == ERR_SAME_TEXTURE)
		printf("Redundance for TEXTURE.\n");
	else if (err == ERR_BAD_SYNTAXE_TEXTURE)
		printf("Invalide syntax for TEXTURE.\n");
	else if (err == ERR_MISSING_TEXTURE)
		printf("MESSING: a TEXTURE.\n");
	else if (err == ERR_MISSING_MAP)
		printf("MESSING: a MAP.\n");
	else
		show_end2(err);
}
