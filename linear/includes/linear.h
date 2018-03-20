/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 13:42:51 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/13 18:50:31 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEAR_H
# define LINEAR_H
# include <math.h>

typedef struct	s_point3d
{
	float		x;
	float		y;
	float		z;
}				t_point3d;

typedef struct	s_point2d
{
	float		x;
	float		y;
}				t_point2d;

typedef struct	s_vector3d
{
	float		x;
	float		y;
	float		z;
}				t_vector3d;

t_point2d		point2d(const float x,
		const float y);

t_point3d		point3d(const float x,
		const float y,
		const float z);

t_vector3d		vector3df(const float x,
		const float y,
		const float z);

t_vector3d		vector3dp(const t_point3d start,
		const t_point3d end);

t_vector3d		product(const float arg,
		const t_vector3d vector);

float			dot_product(const t_vector3d a,
		const t_vector3d b);

t_vector3d		vector_sum(const t_vector3d a,
		const t_vector3d b);

t_vector3d		cross_product(const t_vector3d a,
		const t_vector3d b);

float			sqr_module(const t_vector3d v);

float			module(const t_vector3d v);

float			cosine(const t_vector3d v1,
		const t_vector3d v2);

float			angle(const t_vector3d v1,
		const t_vector3d v2);

void			normalize(t_vector3d *const v);

t_vector3d		reflect_ray(const t_vector3d incident_ray,
		const t_vector3d norm_v);

t_vector3d		rotate_vector_x(const t_vector3d p,
		const float sin_al,
		const float cos_al);

t_vector3d		rotate_vector_y(const t_vector3d p,
		const float sin_al,
		const float cos_al);

t_vector3d		rotate_vector_z(const t_vector3d p,
		const float sin_al,
		const float cos_al);
#endif
