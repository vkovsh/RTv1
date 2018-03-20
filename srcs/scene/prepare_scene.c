/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:26:10 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/14 17:57:27 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>

static inline void	rebuild_kd_tree(t_scene *scene)
{
	if (scene->kd_tree)
		release_kd_tree(scene->kd_tree);
	scene->kd_tree = build_kd_tree(scene->objects,
			scene->last_object_index + 1);
}

void	prepare_scene(t_scene *const scene)
{
	rebuild_kd_tree(scene);
}
