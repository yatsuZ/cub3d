/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:57:37 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/13 17:48:55 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

static void	show_end2(t_error_code err)
{
	if (err == ERR_BAD_SYNTAXE_MAP)
		printf("ERROR: Invalide syntax for MAP.\n");
}

void	show_end(t_error_code err)
{
	printf("");
	if (err == ERR_MALLOC)
		printf("ERROR: Malloc Fail.\n");
	else if (err == ERR_UNKNOW)
		printf("ERROR: ?? ??.\n");
	else if (err == ERR_IS_DIR)
		printf("ERROR: File is a directory.\n");
	else if (err == ERR_OPEN)
		perror("ERROR: ");
	else if (err == ERR_INVALID_FILE)
		printf("ERROR: Invalid file format.\n");
	else if (err == ERR_TO_MUCH_LINE)
		printf("ERROR: OVERFLOW: To much line into \"[file].cub\" .\n");
	else if (err == ERR_SAME_TEXTURE)
		printf("ERROR: Redundance for TEXTURE.\n");
	else if (err == ERR_BAD_SYNTAXE_TEXTURE)
		printf("ERROR: Invalide syntax for TEXTURE.\n");
	else if (err == ERR_MISSING_TEXTURE)
		printf("ERROR: MESSING: a TEXTURE.\n");
	else if (err == ERR_MISSING_MAP)
		printf("ERROR: MESSING: a MAP.\n");
	else if (err == ERR_NULL)
		printf("SUCCESS.\n");
	else
		show_end2(err);
}
