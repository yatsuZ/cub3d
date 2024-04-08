/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:09:45 by lazanett          #+#    #+#             */
/*   Updated: 2024/04/08 18:39:38 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../Header/cub3d.h"

// calcul DIRECTION DU RAYON en fonction de la pos de la cam
// DDA (Digital Differential Analysis) = algo pour trouver les murs rencontrés par le rayon.
// all->file->camera.x = pos horizontal du rayon dans l'espace de la camera
// all->file->dir = calculer la direction du rayon
// all->file->map = coordonnées de la position de la caméra
// all->file->hit = colision
void	init_dda(t_all_data *all, int i) 
{
	all->file->camera.x = 2 * i / (float)all->mini->sizex - 1.0f;
	all->file->dir.x = all->file->raydir.x + (all->file->rayplane.x \
		* all->file->camera.x);
	all->file->dir.y = all->file->raydir.y + (all->file->rayplane.y \
		* all->file->camera.x);
	all->file->map.x = (int)all->file->campos.x;
	all->file->map.y = (int)all->file->campos.y;
	all->file->hit = 0;
}

// calcul les valeurs de deplacementdelta pour x et y en fcontion de la direction du rayon.
// if (all->file->dir.x == 0) ==> rayon est parallele a l'axe donc delta init 1e30 pour eviter / 0
// all->file->delta = distance que le rayon doit parcourir sur chaque axe avant de rencontrer le prochain mur dans cette direction.

void	calcul_delta(t_all_data *all)
{
	if (all->file->dir.x == 0.0f)
		all->file->delta.x = 1e30; //FLT_MAX
	else
		all->file->delta.x = conv_neg(1 / all->file->dir.x);
	if (all->file->dir.y == 0.0f)
		all->file->delta.y = 1e30; //FLT_MAX
	else
		all->file->delta.y = conv_neg(1 / all->file->dir.y);
}

//quelle direction et à quelle distance le rayon doit être déplacé à chaque étape en fonction de la direction du rayon
//sidedist.x = distance horizontal avant de rencontrer un mur dans cette direction
//sidedist.y = distance vertical avant de rencontrer un mur dans cette direction
//if (all->file->dir.x < 0) ==> gauche ; else ==> droite
//if (all->file->dir.y < 0) ==> haut ; else ==> bas
void	perform_dda(t_all_data *all)
{
	if (all->file->dir.x < 0)
	{
		all->file->step.x = -1; 
		all->file->sidedist.x = (all->file->campos.x - all->file->map.x) * \
				all->file->delta.x;
	}
	else
	{
		all->file->step.x = 1;
		all->file->sidedist.x = (all->file->map.x  + 1.0f - all->file->campos.x) * \
				all->file->delta.x; 
	}
	if (all->file->dir.y < 0)
	{
		all->file->step.y = -1;
		all->file->sidedist.y = (all->file->campos.y- all->file->map.y) * \
				all->file->delta.y;
	}
	else
	{
		all->file->step.y = 1;
		all->file->sidedist.y = (all->file->map.y  + 1.0f - all->file->campos.y) * \
				all->file->delta.y;
	}
}

// all->file->sidedist = distance que le rayon doit parcourir sur les axes x et y avant de rencontrer le prochain mur dans cette direction.
// Selon la direction la plus proche d'un mur, la fonction met à jour la position du rayon en ajoutant les déplacements delta
// Si le rayon rencontre un mur alors hit = 1;
void	handle_no_colision(t_all_data *all)
{
	while (all->file->hit == 0)
	{
		if (all->file->sidedist.x < all->file->sidedist.y)
		{
			all->file->sidedist.x += all->file->delta.x;
			all->file->map.x += all->file->step.x;
			all->file->side = 0;
		}
		else
		{
			all->file->sidedist.y += all->file->delta.y;
			all->file->map.y += all->file->step.y;
			all->file->side = 1;
		}
		if ((all->file->mapp[(int)all->file->map.y][(int)all->file->map.x]) == '1')//
			all->file->hit = 1;
	}
}
// calcule la distance du mur à la caméra
// détermine la hauteur du mur à dessiner à l'écran
void	limit_wall_height(t_all_data *all)
{
	if (all->file->side == 0)
		all->file->distwall = (all->file->sidedist.x - all->file->delta.x);
	else
		all->file->distwall = (all->file->sidedist.y - all->file->delta.y);
	all->file->line_height = (int)(all->mini->sizey / all->file->distwall); 
	

	all->file->drawstart = -all->file->line_height / 2 + all->mini->sizey / 2;
	
	if (all->file->drawstart < 0)
		all->file->drawstart = 0;
	
	
	all->file->drawend = all->file->line_height / 2 + all->mini->sizey / 2;;
	
	if (all->file->drawend >= all->mini->sizey)
		all->file->drawend = all->mini->sizey -1; // pas de -1 chez livia
}
