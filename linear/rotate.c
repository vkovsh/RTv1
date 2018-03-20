/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:48:57 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/08 14:51:45 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear.h"

t_vector3d		rotate_vector_x(const t_vector3d p,
		const float sin_al,
		const float cos_al)
{
	float		y;
	float		z;

	y = p.y * cos_al - p.z * sin_al;
	z = p.y * sin_al + p.z * cos_al;
	return (vector3df(p.x, y, z));
}

t_vector3d		rotate_vector_y(const t_vector3d p,
		const float sin_al,
		const float cos_al)
{
	float		x;
	float		z;

	x = p.x * cos_al - p.z * sin_al;
	z = p.x * sin_al + p.z * cos_al;
	return (vector3df(x, p.y, z));
}

t_vector3d		rotate_vector_z(const t_vector3d p,
		const float sin_al,
		const float cos_al)
{
	float		x;
	float		y;

	x = p.x * cos_al - p.z * sin_al;
	y = p.y * cos_al - p.z * sin_al;
	return (vector3df(x, y, p.z));
}
