/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:06:32 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/14 18:10:54 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>

void	render_scene(const t_scene *const scene,
		const t_camera *const camera,
		t_canvas *canvas)
{
	const int w = canvas->w;
	const int h = canvas->h;
	const float dx = canvas->w / 2.0;
	const float dy = canvas->h / 2.0;
	const float focus = camera->proj_plane_dist;
	int	i = -1;
	int	j = -1;

	while (++i < w) 
	{
		while (++j < h)
		{
			const float x = i - dx;
			const float y = j - dy;
			const t_vector3d ray = vector3df(x, y, focus);
			const t_color col = trace(scene, camera, ray);
			set_pixel(pixel(point2d(i, j), col), canvas);
		}
		j = -1;
	}
}
