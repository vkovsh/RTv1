/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light_source.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:30:46 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/12 16:58:13 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_sun3d		*new_light_source(const t_point3d location,
		const t_color color)
{
	t_sun3d	*ls;

	if (!(ls = (t_sun3d *)malloc(sizeof(t_sun3d))))
		return (NULL);
	ls->location = location;
	ls->color = color;
	ls->location_world = location;
	return (ls);
}
