/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_viewable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:33:59 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/13 18:56:00 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		is_viewable(const t_point3d target_point,
		const t_point3d starting_point,
		const t_scene *const scene)
{
	const t_vector3d ray = vector3dp(starting_point, target_point);
	const float target_dist = module(ray);
	t_obj3d *nearest_obj = NULL;
	t_point3d nearest_intersection_point;
	float nearest_intersection_point_dist;
	if (find_intersection_tree(scene->kd_tree,
				starting_point,
				ray,
				&nearest_obj,
				&nearest_intersection_point,
				&nearest_intersection_point_dist))
		return (target_dist < nearest_intersection_point_dist);
	return (1);
}
