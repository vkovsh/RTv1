/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:30:39 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/12 17:45:48 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static inline void	rotate_al_x(t_camera *const cam,
		const float al_x)
{
	if (fabs(al_x) > EPSILON)
	{
		cam->al_x += al_x;
		cam->sin_al_x = sin(cam->al_x);
		cam->cos_al_x = cos(cam->al_x);
	}
}

static inline void	rotate_al_y(t_camera *const cam,
		const float al_y)
{
	if (fabs(al_y) > EPSILON)
	{
		cam->al_y += al_y;
		cam->sin_al_y = sin(cam->al_y);
		cam->cos_al_y = cos(cam->al_y);
	}
}

static inline void	rotate_al_z(t_camera *const cam,
		const float al_z)
{
	if (fabs(al_z) > EPSILON)
	{
		cam->al_z += al_z;
		cam->sin_al_z = sin(cam->al_z);
		cam->cos_al_z = cos(cam->al_z);
	}
}

void				rotate_camera(t_camera *const cam,
		const float al_x,
		const float al_y,
		const float al_z)
{
	rotate_al_x(cam, al_x);
	rotate_al_y(cam, al_y);
	rotate_al_z(cam, al_z);
}
