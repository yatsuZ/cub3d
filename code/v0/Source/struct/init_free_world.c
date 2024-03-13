/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:49:09 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/13 17:57:55 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

static bool	is_a_legit_syntaxe_map(char **texte, int start_i)
{
	int		i;

	i = start_i;
	while (texte[i])
	{
		if (is_a_legit_line_map(texte[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

static t_error_code
	legit_map(t_world_data *world)
{
	if (world == NULL)
		return (ERR_MALLOC);
	return (ERR_NULL);
}

int	init_world(t_file_cub *fcb, t_error_code *err, t_world_data **world)
{
	t_xy	p;

	if (!world || !err || !fcb || *err != ERR_NULL)
		return (1);
	*world = ft_calloc(1, sizeof(t_world_data));
	if (!(*world))
		return (*err = ERR_MALLOC, 1);
	(*world)->i_spawn = -1;
	(*world)->j_spawn = -1;
	(*world)->start_angle = IDK;
	(*world)->map = NULL;
	if (is_a_legit_syntaxe_map(fcb->contained_by_line, fcb->start_map) == false)
		return (*err = ERR_BAD_SYNTAXE_MAP);
	p.x = fcb->start_map;
	p.y = 0;
	init_all_cellules(&(*world)->map, fcb->contained_by_line, p, err);
	if (*err != ERR_NULL)
		return (1);
	*err = legit_map(*world);
	return (*err != ERR_NULL);
}

void	free_world(t_world_data **world)
{
	if (!world || !*world)
		return ;
	free_all_cellules(&(*world)->map);
	free(*world);
	*world = NULL;
}
