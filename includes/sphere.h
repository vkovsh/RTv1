/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:46:21 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/13 16:34:55 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

t_material	get_sphere_material(const void *data,
		const t_point3d intersection_point);

t_point3d	get_max_sphere_boundary_point(const void *data);

t_point3d	get_min_sphere_boundary_point(const void *data);

t_vector3d	get_sphere_normal_vector(const void *data,
		const t_point3d intersection_point);

t_color		get_sphere_color(const void *data,
		const t_point3d intersection_point);

int			intersect_sphere(const void *data,
		const t_point3d v_s,
		const t_vector3d v,
		t_point3d *i_p);

void		release_sphere_data(void *data);
#endif
