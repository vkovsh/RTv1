/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_bondary_point.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:14:12 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/13 16:16:43 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_point3d		get_min_sphere_boundary_point(const void *data)
{
	t_sphere	*sphere;
	t_point3d	c;
	float		r;

	sphere = (t_sphere *)data;
	c = sphere->center;
	r = sphere->radius;
	return (point3d(c.x - r - 1, c.y - r - 1, c.z - r - 1));
}

t_point3d       get_max_sphere_boundary_point(const void *data)
{
	t_sphere    *sphere;
	t_point3d   c;
	float       r;

	sphere = (t_sphere *)data;
	c = sphere->center;
	r = sphere->radius;
	return (point3d(c.x + r + 1, c.y + r + 1, c.z + r + 1));
}
