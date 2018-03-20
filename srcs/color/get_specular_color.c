/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specular_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:23:01 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/13 18:54:14 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		get_specular_color(const t_point3d point,
		const t_vector3d reflected_ray,
		const t_scene *const scene,
		const float p)
{
	t_color light_color = rgb(0, 0, 0);
	t_sun3d *ls;
	t_vector3d v_ls;
	float cos_ls;
	t_color color_ls;
	int i;
	for (i = 0; i < scene->last_light_source_index + 1; i++)
	{
		if (scene->light_sources[i])
		{
			ls = scene->light_sources[i];
			if (is_viewable(ls->location, point, scene))
			{
				v_ls = vector3dp(point, ls->location);
				cos_ls = cosine(reflected_ray, v_ls);
				if (cos_ls > EPSILON)
				{
					color_ls = mul_color(ls->color, pow(cos_ls, p));
					light_color = add_colors(light_color, color_ls);
				}
			}
		}
	}
	return (light_color);
}
