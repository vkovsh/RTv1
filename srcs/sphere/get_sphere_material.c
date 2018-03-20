/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_material.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:17:19 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/13 16:18:58 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_material		get_sphere_material(const void *data,
		const t_point3d intersection_point)
{
	t_sphere	*sphere;
	
	int k = intersection_point.x;
    k++;
	sphere = (t_sphere *)data;
	return (sphere->material);
}
