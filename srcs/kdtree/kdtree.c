/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kdtree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:23:58 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/14 17:37:01 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				point_in_voxel(const t_point3d p,
		const t_voxel v)
{
	return ((p.x > v.x_min) && (p.x < v.x_max) &&
			(p.y > v.y_min) && (p.y < v.y_max) &&
			(p.z > v.z_min) && (p.z < v.z_max));
}

int				filter_overlapped_objects(t_obj3d **const objects,
		const int objects_count,
		const t_voxel v)
{
   	int			i;
	int			j;
	t_obj3d		*tmp;

	i = 0;
	j = objects_count - 1;
	while (i <= j)
	{
		while ((i < j) && (object_in_voxel(objects[i], v)))
			i++;
		while((j > i) && (!object_in_voxel(objects[j], v)))
			j--;
		tmp = objects[i];
		objects[i] = objects[j];
		objects[j] = tmp;
		i++;
		j--;
	}
	return (i);
}

void			split_voxel(const t_voxel v,
		const enum e_plane p,
		const t_coord c,
		t_voxel *const vl,
		t_voxel *const vr)
{
	*vl = v;
	*vr = v;
	if (p == XY)
	{
		vl->z_max = c.z;
		vr->z_min = c.z;
	}
	else if (p == XZ)
	{
		vl->y_max = c.y;
		vr->y_min = c.y;
	}
	else if (p == YZ)
	{
		vl->x_max = c.x;
		vr->x_min = c.x;
	}
	else
		exit(1);
}

void	find_plane(t_obj3d **objects,
		const int objects_count,
		const t_voxel v,
		const int tree_depth,
		enum e_plane *const p,
		t_coord *const c)
{
	if ((tree_depth >= MAX_TREE_DEPTH) || (objects_count <= OBJECTS_IN_LEAF))
	{
		*p = NONE;
		return ;
	}
	const float hx = v.x_max - v.x_min;
	const float hy = v.y_max - v.y_min;
	const float hz = v.z_max - v.z_min;
	// Calculating square of each side of initial voxel
	float Sxy = hx * hy;
	float Sxz = hx * hz;
	float Syz = hy * hz;
	const float Ssum = Sxy + Sxz + Syz;
	// Let's normalize square of each side of initial voxel
	// to satisfy the following relationship:
	// Sxy + Sxz + Syz = 1
	Sxy /= Ssum;
	Sxz /= Ssum;
	Syz /= Ssum;
	const int max_splits = MAX_SPLITS_OF_VOXEL;
	const float split_cost = SPLIT_COST;
	// Assume that at the beginning best SAH has initial voxel
	// SAH = 0.5 * square * objects_col
	// square of initial voxel is Sxy + Sxz + Syz = 1
	float bestSAH = objects_count;
	*p = NONE;
	float currSAH;
	t_coord curr_split_coord;
	int i;
	t_voxel vl;
	t_voxel vr;
	float l;
	float r;
	float S_split;
	float S_non_split;
	// Let's find split surface, which have the least SAH
	// trying to minimize SAH by splitting across XY plane
	S_split = Sxy;
	S_non_split = Sxz + Syz;
	for (i = 1; i < max_splits; i++)
	{
		l = ((float) i) / max_splits;
		r = 1 - l;
		// Current coordinate of split surface
		curr_split_coord.z = v.z_min + l * hz;
		split_voxel(v, XY, curr_split_coord, &vl, &vr);
		currSAH = (S_split + l * S_non_split) * objects_in_voxel(objects, objects_count, vl)
			+ (S_split + r * S_non_split) * objects_in_voxel(objects, objects_count, vr)
			+ split_cost;
		if (currSAH < bestSAH)
		{
			bestSAH = currSAH;
			*p = XY;
			*c = curr_split_coord;
		}
	}
	// trying to minimize SAH by splitting across XZ plane
	S_split = Sxz;
	S_non_split = Sxy + Syz;
	for (i = 1; i < max_splits; i++)
	{
		l = ((float) i) / max_splits;
		r = 1 - l;
		// Current coordinate of split surface
		curr_split_coord.y = v.y_min + l * hy;
		split_voxel(v, XZ, curr_split_coord, &vl, &vr);
		currSAH = (S_split + l * S_non_split) * objects_in_voxel(objects, objects_count, vl)
			+ (S_split + r * S_non_split) * objects_in_voxel(objects, objects_count, vr)
			+ split_cost;
		if (currSAH < bestSAH)
		{
			bestSAH = currSAH;
			*p = XZ;
			*c = curr_split_coord;
		}
	}
	// trying to minimize SAH by splitting across YZ plane
	S_split = Syz;
	S_non_split = Sxy + Sxz;
	for (i = 1; i < max_splits; i++)
	{
		l = ((float) i) / max_splits;
		r = 1 - l;
		// Current coordinate of split surface
		curr_split_coord.x = v.x_min + l * hx;
		split_voxel(v, YZ, curr_split_coord, &vl, &vr);
		currSAH = (S_split + l * S_non_split) * objects_in_voxel(objects, objects_count, vl)
			+ (S_split + r * S_non_split) * objects_in_voxel(objects, objects_count, vr)
			+ split_cost;
		if (currSAH < bestSAH)
		{
			bestSAH = currSAH;
			*p = YZ;
			*c = curr_split_coord;
		}
	}
}

int			objects_in_voxel(t_obj3d **objects,
		const int objects_count,
		const t_voxel v)
{
	int		i;
	int		count = 0;
	for (i = 0; i < objects_count; i++)
		if (object_in_voxel(objects[i], v))
			++count;
	return (count);
}

int				object_in_voxel(t_obj3d *const obj,
		const t_voxel v)
{
	t_point3d min_p = obj->get_min_boundary_point(obj->data);
	t_point3d max_p = obj->get_max_boundary_point(obj->data);
	return (!((max_p.x < v.x_min)
				|| (max_p.y < v.y_min)
				|| (max_p.z < v.z_min)
				|| (min_p.x > v.x_max)
				|| (min_p.y > v.y_max)
				|| (min_p.z > v.z_max)));
}

t_kdnode		*make_leaf(t_obj3d **objects,
		int objects_count)
{
	t_kdnode	*leaf;

	if (!(leaf = (t_kdnode *)malloc(sizeof(t_kdnode))))
		return (NULL);
	leaf->plane = NONE;
	leaf->objects_count = objects_count;
	leaf->l = NULL;
	leaf->r = NULL;
	if (objects_count)
		leaf->objects = (t_obj3d **)malloc(objects_count * sizeof(t_obj3d *));
	else
		leaf->objects = NULL;
	ft_memcpy(leaf->objects, objects, objects_count * sizeof(t_obj3d *));
	return (leaf);
}


int				vector_plane_intersection(const t_vector3d vector,
		const t_point3d vector_start,
		const enum e_plane plane,
		const t_coord coord,
		t_point3d *const result) 
{
	float k;
	switch(plane)
	{
		case XY:
			if (((coord.z < vector_start.z) && (vector.z > 0))
					|| ((coord.z > vector_start.z) && (vector.z < 0)))
				return (0);
			k = (coord.z - vector_start.z) / vector.z;
			*result = point3d(vector_start.x + vector.x * k,
					vector_start.y + vector.y * k,
					coord.z);
			break;
		case XZ:
			if (((coord.y < vector_start.y) && (vector.y > 0))
					|| ((coord.y > vector_start.y) && (vector.y < 0)))
				return (0);
			k = (coord.y - vector_start.y) / vector.y;
			*result = point3d(vector_start.x + vector.x * k,
					coord.y, vector_start.z + vector.z * k);
			break;
		case YZ:
			if (((coord.x < vector_start.x) && (vector.x > 0))
					|| ((coord.x > vector_start.x) && (vector.x < 0)))
				return (0);
			k = (coord.x - vector_start.x) / vector.x;
			*result = point3d(coord.x,
					vector_start.y + vector.y * k,
					vector_start.z + vector.z * k);
			break;
		case NONE:
			exit(1);
			break;
	}
	return (1);
}

int			voxel_intersection(const t_vector3d vector,
		const t_point3d vector_start,
		const t_voxel v)
{
	if (point_in_voxel(vector_start, v))
		return (1);
	t_point3d p;
	t_coord c;
	c.z = v.z_min;
	if (vector_plane_intersection(vector, vector_start, XY, c, &p)
			&& (p.x > v.x_min) && (p.x < v.x_max)
			&& (p.y > v.y_min) && (p.y < v.y_max))
		return (1);
	c.z = v.z_max;
	if (vector_plane_intersection(vector, vector_start, XY, c, &p)
			&& (p.x > v.x_min) && (p.x < v.x_max)
			&& (p.y > v.y_min) && (p.y < v.y_max))
		return (1);
	c.y = v.y_min;
	if (vector_plane_intersection(vector, vector_start, XZ, c, &p)
			&& (p.x > v.x_min) && (p.x < v.x_max)
			&& (p.z > v.z_min) && (p.z < v.z_max))
		return (1);
	c.y = v.y_max;
	if (vector_plane_intersection(vector, vector_start, XZ, c, &p)
			&& (p.x > v.x_min) && (p.x < v.x_max)
			&& (p.z > v.z_min) && (p.z < v.z_max))
		return (1);
	c.x = v.x_min;
	if (vector_plane_intersection(vector, vector_start, YZ, c, &p)
			&& (p.y > v.y_min) && (p.y < v.y_max)
			&& (p.z > v.z_min) && (p.z < v.z_max))
		return (1);
	c.x = v.x_max;
	if (vector_plane_intersection(vector, vector_start, YZ, c, &p)
			&& (p.y > v.y_min) && (p.y < v.y_max)
			&& (p.z > v.z_min) && (p.z < v.z_max))
		return (1);
	return (0);;
}

int			find_intersection_node(t_kdnode *const node,
		const t_voxel v,
		const t_point3d vector_start,
		const t_vector3d vector,
		t_obj3d **const nearest_obj_ptr,
		t_point3d *const nearest_intersection_point_ptr,
		float *const nearest_intersection_point_dist_ptr) 
{
	// Is leaf
	if (node->plane == NONE)
	{
		if ((node->objects_count) && (node->objects))
		{
			int i;
			t_obj3d *obj = NULL;
			t_point3d intersection_point;
			float sqr_curr_dist;
			t_obj3d *nearest_obj = NULL;
			t_point3d nearest_intersection_point;
			float sqr_nearest_dist;
			int intersected = 0;
			// Finding nearest object and intersection point
			for (i = 0; i < node->objects_count; i++)
			{
				if (node->objects[i])
				{
					obj = node->objects[i];
					if ((obj->intersect(obj->data, vector_start, vector, &intersection_point))
							&& (point_in_voxel(intersection_point, v)))
					{
						sqr_curr_dist = sqr_module(vector3dp(vector_start, intersection_point));
						if ((sqr_curr_dist < sqr_nearest_dist) || (!intersected))
						{
							nearest_obj = obj;
							nearest_intersection_point = intersection_point;
							sqr_nearest_dist = sqr_curr_dist;
							intersected = 1;
						}
					}
				}
			}
			if (intersected)
			{
				float nearest_dist = sqrt(sqr_nearest_dist);
				if(nearest_dist < *nearest_intersection_point_dist_ptr)
				{
					*nearest_intersection_point_dist_ptr = nearest_dist;
					*nearest_obj_ptr = nearest_obj;
					*nearest_intersection_point_ptr = nearest_intersection_point;
				}
			}
			return (intersected);
		}
		return (0);
	}
	//othervise
	t_voxel front_voxel;
	t_voxel back_voxel;
	t_kdnode *front_node;
	t_kdnode *back_node;
	switch (node->plane)
	{
		case XY:
			if (((node->coord.z > v.z_min) && (node->coord.z > vector_start.z))
				|| ((node->coord.z < v.z_min) && (node->coord.z < vector_start.z)))
			{
				front_node = node->l;
				back_node = node->r;
				split_voxel(v, node->plane, node->coord, &front_voxel, &back_voxel);
			}
			else
			{
				front_node = node->r;
				back_node = node->l;
				split_voxel(v, node->plane, node->coord, &back_voxel, &front_voxel);
			}
			break;
		case XZ:
			if(((node->coord.y > v.y_min) && (node->coord.y > vector_start.y))
				|| ((node->coord.y < v.y_min) && (node->coord.y < vector_start.y)))
			{
				front_node = node->l;
				back_node = node->r;
				split_voxel(v, node->plane, node->coord, &front_voxel, &back_voxel);
			}
			else
			{
				front_node = node->r;
				back_node = node->l;
				split_voxel(v, node->plane, node->coord, &back_voxel, &front_voxel);
			}
			break;
		case YZ:
			if(((node->coord.x > v.x_min) && (node->coord.x > vector_start.x))
				|| ((node->coord.x < v.x_min) && (node->coord.x < vector_start.x)))
			{
				front_node = node->l;
				back_node = node->r;
				split_voxel(v, node->plane, node->coord, &front_voxel, &back_voxel);
			}
			else
			{
				front_node = node->r;
				back_node = node->l;
				split_voxel(v, node->plane, node->coord, &back_voxel, &front_voxel);
			}
			break;
		case NONE:
			exit(1);
			break;
	}
	if (voxel_intersection(vector, vector_start, front_voxel)
		&& find_intersection_node(front_node,
			front_voxel,
			vector_start,
			vector,
			nearest_obj_ptr,
			nearest_intersection_point_ptr,
			nearest_intersection_point_dist_ptr))
		return (1);
	return (voxel_intersection(vector, vector_start, back_voxel)
		&& find_intersection_node(back_node,
			back_voxel,
			vector_start,
			vector,
			nearest_obj_ptr,
			nearest_intersection_point_ptr,
			nearest_intersection_point_dist_ptr));
}

int			find_intersection_tree(t_kdtree *const tree,
		const t_point3d vector_start,
		const t_vector3d vector,
		t_obj3d **const nearest_obj_ptr,
		t_point3d *const nearest_intersection_point_ptr,
		float *const nearest_intersection_point_dist_ptr)
{
	return (find_intersection_node(tree->root,
				tree->bounding_box,
				vector_start,
				vector,
				nearest_obj_ptr,
				nearest_intersection_point_ptr,
				nearest_intersection_point_dist_ptr));
}
