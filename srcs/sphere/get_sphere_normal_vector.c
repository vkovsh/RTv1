/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_normal_vector.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:05:33 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/13 16:08:09 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector3d		get_sphere_normal_vector(const void *data,
		const t_point3d intersection_point)
{
	t_sphere	*sphere;
	t_vector3d	n;

	sphere = (t_sphere *)data;
	n = vector3dp(sphere->center,
			intersection_point);
	normalize(&n);
	return (n);
}
