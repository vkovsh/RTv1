/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:43 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/12 15:03:03 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color				rgb(const unsigned char r,
		const unsigned char g,
		const unsigned char b)
{
	t_color			color;

	color.r = r;
	color.g = g;
	color.b	= b;
	return (color);
}

t_color				add_colors(const t_color c1,
		const t_color c2)
{
	int				r;
	int				g;
	int				b;

	r = (int)c1.r + c2.r;
	g = (int)c1.g + c2.g;
	b = (int)c1.b + c2.b;
	r = (r < MAX_R) ? r : MAX_R;
	g = (g < MAX_G) ? g : MAX_G;
	b = (b < MAX_B) ? b : MAX_B;
	return (rgb((unsigned char)r,
				(unsigned char)g,
				(unsigned char)b));
}

t_color				mul_color(const t_color c1,
		const double k)
{
	t_color			color;

	color.r = (unsigned char)(c1.r * k);
	color.g = (unsigned char)(c1.g * k);
	color.b = (unsigned char)(c1.b * k);
	return (color);
}

t_color				grayscale(const t_color c)
{
	unsigned char	gray;

	gray = (unsigned char)(0.2126 * c.r + 0.7152 * c.g
			+ 0.0722 * c.b);
	return (rgb(gray, gray, gray));
}

t_color				mix_colors(const t_color c1,
		const t_color c2)
{
	int				r;
	int				g;
	int				b;

	r = (c1.r * c2.r) >> 8;
	g = (c1.g * c2.g) >> 8;
	b = (c1.b * c2.b) >> 8;
	return (rgb((unsigned char)r,
				(unsigned char)g,
				(unsigned char)b));
}
