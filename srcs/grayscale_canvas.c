/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grayscale_canvas.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:05:46 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/16 15:19:56 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_canvas		*grayscale_canvas(t_canvas *base)
{
	t_canvas	*grayscaled;
	int			i;
	int			j;
	int			i_max;
	int			j_max;

	grayscaled = new_canvas(base->w, base->h);
	i = -1;
	i_max = base->h;
	j_max = base->w;
	while (++i < i_max)
	{
		j = -1;
		while (++j < j_max)
			set_pixel(pixel(point2d(i, j),
						grayscale(get_pixel(point2d(i, j), base))),
					grayscaled);
	}
	return (grayscaled);
}
