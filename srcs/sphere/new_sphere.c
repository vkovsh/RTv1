/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:40:22 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/13 15:45:38 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "sphere.h"

t_obj3d			*new_sphere(const t_point3d center,
		const float radius,
		const t_color color,
		const t_material material)
{
	t_sphere	*sphere;
	t_obj3d		*obj;

	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sphere->center = center;
	sphere->radius = radius;
	sphere->color = color;
	sphere->material = material;
	if (!(obj = (t_obj3d *)malloc(sizeof(t_obj3d))))
		return (NULL);
	obj->get_min_boundary_point = get_min_sphere_boundary_point;
	obj->get_max_boundary_point = get_max_sphere_boundary_point;
	obj->intersect = intersect_sphere;
	obj->get_color = get_sphere_color;
	obj->get_material = get_sphere_material;
	obj->get_normal_vector = get_sphere_normal_vector;
	obj->release_data = release_sphere_data;
	obj->data = sphere;
	return (obj);
}
