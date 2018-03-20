/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lighting_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:11:34 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/13 18:51:12 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		get_lighting_color(const t_point3d point,
		const t_vector3d norm_v,
		const t_scene *const scene)
{
	t_color light_color = rgb(0, 0, 0);
	
	//normalize(&norm_v);
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
				//normalize(&v_ls);
				cos_ls = fabs(cosine(norm_v, v_ls));
				color_ls = mul_color(ls->color, cos_ls);
				light_color = add_colors(light_color, color_ls);
			}
		}
	}
	return (light_color);
}
