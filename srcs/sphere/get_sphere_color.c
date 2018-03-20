/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:02:10 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/13 16:04:56 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color			get_sphere_color(const void *data,
		const t_point3d intersection_point)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)data;
	sphere->color.r += !intersection_point.x;
	return (sphere->color);
}
