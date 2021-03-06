/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:51:48 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/16 15:52:58 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		calculate_color(const t_scene *const scene,
		const t_point3d vector_start,
		const t_vector3d vector,
		t_obj3d *const *obj_ptr,
		const t_point3d *const point_ptr,
		const float *const dist_ptr,
		const float intensity,
		const int recursion_level)
{
	int x = vector_start.x;
	x++;
	const t_obj3d *obj = *obj_ptr;
	const t_point3d point = *point_ptr;
	const float dist = *dist_ptr;
	const t_material material = obj->get_material(obj->data, point);
	const t_vector3d norm = obj->get_normal_vector(obj->data, point);
	t_color obj_color = obj->get_color(obj->data, point);
	t_color ambient_color;
	t_color diffuse_color;
	t_color reflected_color;
	t_color specular_color;
	float fog_density = 0;
	if (scene->fog_density)
		fog_density = scene->fog_density(dist, scene->fog_parameters);
	t_vector3d reflected_ray;
	if ((material.ks) || (material.kr))
		reflected_ray = reflect_ray(vector, norm);
	if (material.ka)
		ambient_color = mix_colors(scene->background_color, obj_color);
	if (material.kd) 
	{
		diffuse_color = obj_color;
		if (scene->light_sources_count)
		{
			t_color light_color = get_lighting_color(point, norm, scene);
			diffuse_color = mix_colors(diffuse_color, light_color);
		}
	}
	if (material.ks)
	{
		specular_color = scene->background_color;
		if (scene->light_sources_count)
			specular_color = get_specular_color(point, reflected_ray, scene, material.p);
	}
	if (material.kr) 
	{
		if ((intensity > THRESHOLD_RAY_INTENSITY)
				&& (recursion_level < MAX_RAY_RECURSION_LEVEL))
		{
			reflected_color = trace_recursively(scene,
					point,
					reflected_ray,
					intensity * material.kr * (1 - fog_density),
					recursion_level + 1);
		}
		else
			reflected_color = scene->background_color;
	}
	t_color result_color = rgb(0, 0, 0);
	if (material.ka)
		result_color = add_colors(result_color,
				mul_color(ambient_color, material.ka));
	if (material.kd)
		result_color = add_colors(result_color,
				mul_color(diffuse_color, material.kd));
	if (material.ks)
		result_color = add_colors(result_color,
				mul_color(specular_color, material.ks));
	if (material.kr)
		result_color = add_colors(result_color,
				mul_color(reflected_color, material.kr));
	if(scene->fog_density)
		result_color = add_colors(mul_color(scene->background_color, fog_density),
				mul_color(result_color, 1 - fog_density));
	return (result_color);
}
