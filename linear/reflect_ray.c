/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:55:11 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/08 14:56:51 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear.h"

t_vector3d		reflect_ray(const t_vector3d incident_ray,
		const t_vector3d norm_v)
{
	float		k;
	float		x;
	float		y;
	float		z;

	k = 2 * dot_product(incident_ray, norm_v) / sqr_module(norm_v);
	x = incident_ray.x - norm_v.x * k;
	y = incident_ray.y - norm_v.y * k;
	z = incident_ray.z - norm_v.z * k;
	return (vector3df(x, y, z));
}
