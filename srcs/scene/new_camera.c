/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:17:48 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/12 17:25:57 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_camera		*new_camera(const t_point3d camera_position,
		const float al_x,
		const float al_y,
		const float al_z,
		const float proj_plane_dist)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)malloc(sizeof(t_camera))))
		return (NULL);
	camera->camera_position = camera_position;
	camera->al_x = al_x;
	camera->sin_al_x = sin(al_x);
	camera->cos_al_x = cos(al_x);
	camera->al_y = al_y;
	camera->sin_al_y = sin(al_y);
	camera->cos_al_y = cos(al_y);
	camera->al_z = al_z;
	camera->sin_al_z = sin(al_z);
	camera->cos_al_z = cos(al_z);
	camera->proj_plane_dist = proj_plane_dist;
	return (camera);
}
