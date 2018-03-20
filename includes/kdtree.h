/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kdtree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:25:50 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/14 15:06:36 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KDTREE_H
# define KDTREE_H
# define MAX_TREE_DEPTH 20
# define OBJECTS_IN_LEAF 1
# define MAX_SPLITS_OF_VOXEL 5
# define SPLIT_COST 5

enum				e_plane
{
	XY,
	XZ,
	YZ,
	NONE
}					t_plane;

typedef	union		u_coord
{
	float			x;
	float			y;
	float			z;
}					t_coord;

typedef struct		s_voxel
{
	float			x_min;
	float			y_min;
	float			z_min;
	float			x_max;
	float			y_max;
	float			z_max;
}					t_voxel;

typedef struct		s_kdnode
{
	enum e_plane	plane;
	union u_coord	coord;
	struct s_obj3d	**objects;
	int				objects_count;
	struct s_kdnode	*l;
	struct s_kdnode	*r;
}					t_kdnode;

typedef struct		s_kdtree
{
	struct s_kdnode	*root;
	struct s_voxel	bounding_box;
}					t_kdtree;
#endif
