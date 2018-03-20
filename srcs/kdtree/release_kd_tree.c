/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_kd_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:45:23 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/14 14:04:11 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	release_node_objects(t_obj3d **objects,
		int count)
{
	int		i;

	i = -1;
	while (++i < count)
		release_object3d(objects[i]);
	free(objects);
}

static void	release_kd_node(t_kdnode *node)
{
	if (node->l)
		release_kd_node(node->l);
	if(node->r)
		release_kd_node(node->r);
	if(node->objects)
		release_node_objects(node->objects, node->objects_count);
	free(node);
}

void		release_kd_tree(t_kdtree *tree)
{
	release_kd_node(tree->root);
	free(tree);
}
