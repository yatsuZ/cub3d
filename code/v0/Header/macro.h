/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:28:00 by yzaoui            #+#    #+#             */
/*   Updated: 2024/03/25 16:44:10 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# include "./struct.h"

# define CHAR_ALLOWED(c) ((c == ' ') || (c == '0') || (c == '1') || \
(c == 'N') || (c == 'S') || (c == 'E') || (c == 'W') || (c == '\n'))

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

# define FLOOR 0
# define CEIL 1

# endif