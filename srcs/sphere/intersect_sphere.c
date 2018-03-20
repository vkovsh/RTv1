/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:55:13 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/13 16:00:47 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static inline float get_t(const float t1,
		const float t2)
{
	float			min_t;
	float			max_t;
	float			t;

	min_t = (t1 < t2) ? t1 : t2;
	max_t = (t1 > t2) ? t1 : t2;
	t = (min_t > EPSILON) ? min_t : max_t;
	return (t);
}

int					intersect_sphere(const void *data,
		const t_point3d v_s,
		const t_vector3d v,
		t_point3d *i_p)
{
	t_sphere		*s;
	float			a;
	float			b;
	float			c;
	float			d;

	s = (t_sphere *)data;
	a = v.x * v.x + v.y * v.y + v.z * v.z;
	b = 2 * (v.x * (v_s.x - s->center.x)
			+ v.y * (v_s.y - s->center.y)
			+ v.z * (v_s.z - s->center.z));
	c = s->center.x * s->center.x + s->center.y * s->center.y
		+ s->center.z * s->center.z
		+ v_s.x * v_s.x + v_s.y * v_s.y + v_s.z * v_s.z
		- 2 * (v_s.x * s->center.x + v_s.y * s->center.y
				+ v_s.z * s->center.z) - s->radius * s->radius;
	if ((d = b * b - 4 * a * c) < 0)
		return (0);
	a *= 2;
	d = sqrt(d);
	if ((c = get_t((-b + d) / a, (-b - d) / a)) < EPSILON)
		return (0);
	*i_p = point3d(v_s.x + c * v.x, v_s.y + c * v.y, v_s.z + c * v.z);
	return (1);
}
