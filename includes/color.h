/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:21:42 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/12 15:04:02 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct			s_color
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_color;

t_color					rgb(const unsigned char r,
		const unsigned char g,
		const unsigned char b);
t_color					add_colors(const t_color c1,
		const t_color c2);
t_color					mul_color(const t_color c1,
		const double k);
t_color					grayscale(const t_color c);
t_color					mix_colors(const t_color c1,
		const t_color c2);
#endif
