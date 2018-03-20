/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light_source.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:34:32 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/12 16:58:56 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_light_source(t_scene *const scene,
		t_sun3d *const light_source)
{
	int	counter;

	counter = ++scene->last_light_source_index;
	scene->light_sources[counter] = light_source;
}
