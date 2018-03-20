/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:48:13 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/12 18:06:23 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			move_camera(t_camera *const camera,
		const t_vector3d vector)
{
	t_vector3d	rotate_vector;
	t_point3d	current_position;

	rotate_vector = rotate_vector_z(rotate_vector_y(rotate_vector_x(
					vector,
					camera->sin_al_x,
					camera->cos_al_x),
				camera->sin_al_y,
				camera->cos_al_y),
			camera->sin_al_z,
			camera->cos_al_z);
	current_position = camera->camera_position;
	camera->camera_position = point3d(current_position.x
			+ rotate_vector.x,
			current_position.y
			+ rotate_vector.y,
			current_position.z
			+ rotate_vector.z);
}
