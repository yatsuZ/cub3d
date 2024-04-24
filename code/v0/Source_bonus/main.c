/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:45:46 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/23 14:26:40 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Header/cub3d_bonus.h"

int	end(t_all_data *all)
{
	t_error_code	err_type;

	err_type = ERR_MALLOC;
	if (all)
		err_type = all->err;
	free_all(&all);
	show_end(err_type);
	if (err_type == ERR_NULL)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_all_data	*all;

	if (argc < 2 || argv[1] == NULL)
		return \
	(printf("Error: Missing argument \"[file].cub\" .\n"), EXIT_FAILURE);
	else if (argc > 2)
		return (printf("Error: Too much arg.\n"), EXIT_FAILURE);
	all = NULL;
	if (init_all(&all, argv[1]))
		return (end(all));
	show_end(start_exec(all));
	end(all);
	return (0);
}