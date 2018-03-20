/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:19:28 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/12 16:24:33 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_object(t_scene *const scene,
		t_obj3d *const object)
{
	int	counter;

	counter = ++scene->last_object_index;
	scene->objects[counter] = object;
}
