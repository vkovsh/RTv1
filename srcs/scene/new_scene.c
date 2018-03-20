/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:22:20 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/12 15:59:48 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_scene		*new_scene(const int objects_count,
		const int light_sources_count,
		const t_color background_color)
{
	t_scene	*s;

	if (!(s = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	s->objects_count = objects_count;
	if (!(s->objects = (t_obj3d **)calloc(objects_count,
			sizeof(t_obj3d *))))
		return (NULL);
	s->light_sources_count = light_sources_count;
	if (!(s->light_sources = (t_sun3d **)calloc(light_sources_count,
					sizeof(t_sun3d *))))
		return (NULL);
	s->background_color = background_color;
	s->last_object_index = -1;
	s->last_light_source_index = -1;
	s->fog_parameters = NULL;
	s->fog_density = NULL;
	s->kd_tree = NULL;
	return (s);
}

void		release_scene(t_scene *scene)
{
	int		i;

	i = 0;
	while (i < scene->objects_count)
		release_object3d(scene->objects[i++]);
	free(scene->objects);
	i = 0;
	while (i < scene->light_sources_count)
		free(scene->light_sources[i]);
	free(scene->light_sources);
	if (scene->fog_parameters)
		free(scene->fog_parameters);
	if (scene->kd_tree)
		release_kd_tree(scene->kd_tree);
	free(scene);
}
