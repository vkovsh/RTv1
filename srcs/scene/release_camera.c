/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:27:03 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/12 17:28:39 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	release_camera(t_camera *const camera)
{
	free(camera);
}
