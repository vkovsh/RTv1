/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_layer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:23:44 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/16 19:20:19 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <mlx.h>

static inline void	fill_image_from_canvas(unsigned char *begin,
		const t_canvas *const canvas)
{
	int				i;
	int				j;
	int				i_max;
	int				j_max;
	t_color			color;

	i_max = canvas->h;
	j_max = canvas->w;
	i = -1;
	while (++i < i_max)
	{
		j = -1;
		while (++j < j_max)
		{
			color = get_pixel(point2d(i, j), canvas);
			*begin++ = color.b;
			*begin++ = color.g;
			*begin++ = color.r;
			begin++;
		}
	}
}

void				*canvas_to_image(void *const mlx,
		const t_canvas *const canvas)
{
	void			*begin;
	void			*im_ptr;
	int				bpp;
	int				len;
	int				end;

	im_ptr = mlx_new_image(mlx, canvas->w, canvas->h);
	bpp = 4;
	len = 0;
	end = 0;
	begin = mlx_get_data_addr(im_ptr, &bpp, &len, &end);
	fill_image_from_canvas((unsigned char *)begin, canvas);
	return (im_ptr);
}
