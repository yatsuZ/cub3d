/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:28:00 by yzaoui            #+#    #+#             */
/*   Updated: 2024/04/17 12:25:53 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# include "./struct_bonus.h"

# define CHAR_ALLOWED(c) ((c == ' ') || (c == '0') || (c == '1') || \
(c == 'N') || (c == 'S') || (c == 'E') || (c == 'W') || (c == '\n'))

# define NORTHH 0
# define SOUTHH 1
# define WESTT 2
# define EASTT 3

# define FLOOR 0
# define CEIL 1

#define MINIMAP_SIZE 10
#define MINIMAP_SCALE 5

#endif