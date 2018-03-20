/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:02:09 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/08 15:08:43 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear.h"

t_vector3d	product(const float arg,
		const t_vector3d vector)
{
	return (vector3df(vector.x * arg,
				vector.y * arg,
				vector.z * arg));
}

float		dot_product(const t_vector3d a,
		const t_vector3d b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector3d	vector_sum(const t_vector3d a,
		const t_vector3d b)
{
	return (vector3df(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vector3d	cross_product(const t_vector3d a,
		const t_vector3d b)
{
	return (vector3df(a.z * b.y - a.y * b.z,
				a.x * b.z - a.z * b.x,
				a.y * b.x - a.x * b.y));
}

void		normalize(t_vector3d *const v)
{
	float		mod;

	mod = module(*v);
	v->x /= mod;
	v->y /= mod;
	v->z /= mod;
}
