/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   voxel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:57:22 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/14 15:05:25 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_voxel		voxel(const t_point3d min,
		const t_point3d max)
{
	t_voxel	v;

	v.x_min = min.x - 1;
	v.y_min = min.y - 1;
	v.z_min = min.z - 1;
	v.x_max = max.x + 1;
	v.y_max = max.y + 1;
	v.z_max = max.z + 1;
	return (v);
}
