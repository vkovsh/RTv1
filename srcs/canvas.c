/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:04:07 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/09 14:14:33 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			set_pixel(const t_pixel p,
		t_canvas *const c)
{
	int			offset;

	offset = p.position.y * c->w + p.position.x;
	c->data[offset] = p.color;
}

t_color			get_pixel(const t_point2d p,
		const t_canvas *const c)
{
	int			offset;
	t_color		color;

	offset = p.y * c->w + p.x;
	color = c->data[offset];
	return (color);
}

void			release_canvas(t_canvas *c)
{
	free(c->data);
	free(c);
}

t_canvas		*new_canvas(const int w,
		const int h)
{
	t_canvas	*canvas;

	if (!(canvas = (t_canvas *)malloc(sizeof(t_canvas))))
		return (NULL);
	canvas->w = w;
	canvas->h = h;
	if (!(canvas->data = calloc(w * h + 1, sizeof(t_color))))
		return (NULL);
	return (canvas);
}

void			clear_canvas(t_canvas *c)
{
	ft_memset(c->data, 0, c->w * c->h + 1);
}
