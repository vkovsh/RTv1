/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:16:05 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/08 13:50:02 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear.h"

t_point3d		point3d(const float x,
		const float y,
		const float z)
{
	t_point3d	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}
