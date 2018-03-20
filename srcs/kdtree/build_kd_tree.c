/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_kd_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:07:39 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/14 17:57:55 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>

static void		reinit_voxel_min_max(t_point3d *min_p,
		t_point3d *max_p,
		t_point3d new_min_p,
		t_point3d new_max_p)
{
	if (new_min_p.x < min_p->x)
		min_p->x = new_min_p.x;
	if (new_min_p.y < min_p->y)
		min_p->y = new_min_p.y;
	if (new_min_p.z < min_p->z)
		min_p->z = new_min_p.z;
	if (new_max_p.x > max_p->x)
		max_p->x = new_max_p.x;
	if (new_max_p.y > max_p->y)
		max_p->y = new_max_p.y;
	if (new_max_p.z > max_p->z)
		max_p->z = new_max_p.z;
}

static t_voxel	make_initial_voxel(t_obj3d **objects,
		int objects_count)
{
	t_point3d	min_p;
	t_point3d	max_p;
	int			i;

	if (!objects_count)
		return (voxel(point3d(0, 0, 0), point3d(0, 0, 0)));
	min_p = objects[0]->get_min_boundary_point(objects[0]->data);
	max_p = objects[0]->get_max_boundary_point(objects[0]->data);
	i = 0;
	while (++i < objects_count)
		reinit_voxel_min_max(&min_p,
				&max_p,
				objects[i]->get_min_boundary_point(objects[i]->data),
				objects[i]->get_max_boundary_point(objects[i]->data));
	return (voxel(min_p, max_p));
}

t_kdtree		*build_kd_tree(t_obj3d **const objects,
		const int objects_count)
{
	t_kdtree	*tree;

	if (!(tree = (t_kdtree *)malloc(sizeof(t_kdtree))))
		return (NULL);
	//printf("sphera: %p data: %p\n", objects[0], objects[0]->data);
	tree->bounding_box = make_initial_voxel(objects, objects_count);
	if (!(tree->root = rec_build(objects,
					objects_count,
					tree->bounding_box,
					0)))
		return (NULL);
	return (tree);
}
