/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:20:10 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/14 15:25:51 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_kdnode			*rec_build(t_obj3d **const objects,
		const int objects_count,
		const t_voxel v,
		const int iter)
{
	enum e_plane	p;
	t_coord     	c;
	t_voxel     	vl;
	t_voxel			vr;
	
	find_plane(objects, objects_count, v, iter, &p, &c);
	if (p == NONE)
		return (make_leaf(objects, objects_count));
	split_voxel(v, p, c, &vl, &vr);
	int l_objects_count = filter_overlapped_objects(objects, objects_count, vl);
	t_kdnode *l = rec_build(objects, l_objects_count, vl, iter + 1);
	int r_objects_count = filter_overlapped_objects(objects, objects_count, vr);
	t_kdnode *r = rec_build(objects, r_objects_count, vr, iter + 1);
	t_kdnode *node = (t_kdnode *)malloc(sizeof(t_kdnode));
	node->objects = NULL;
	node->objects_count = 0;
	node->plane = p;
	node->coord = c;
	node->l = l;
	node->r = r;
	return (node);
}

