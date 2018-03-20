/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_sphere_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:53:11 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/13 15:54:43 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			release_sphere_data(void *data)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)data;
	free(sphere);
}
