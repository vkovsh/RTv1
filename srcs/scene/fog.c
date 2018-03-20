/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fog.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:07:53 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/16 15:23:50 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static inline float	exponential_fog_density(const float distance,
		const void *fog_data)
{
	float			*k;

	k = (float *)fog_data;
	return ((float)1 - exp(-(*k) * distance));
}

void				set_no_fog(t_scene *const scene)
{
	if (scene->fog_parameters)
		free(scene->fog_parameters);
	scene->fog_density = NULL;
}

void				set_exponential_fog(t_scene *const scene,
		const float k)
{
	float			*k_p;

	scene->fog_density = exponential_fog_density;
	k_p = malloc(sizeof(float));
	*k_p = k;
	if (scene->fog_parameters)
		free(scene->fog_parameters);
	scene->fog_parameters = k_p;
}
