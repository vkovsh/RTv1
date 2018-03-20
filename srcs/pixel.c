/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:35:31 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/09 14:16:42 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_pixel		pixel(const t_point2d point,
		const t_color color)
{
	t_pixel	p;

	p.position = point;
	p.color = color;
	return (p);
}
