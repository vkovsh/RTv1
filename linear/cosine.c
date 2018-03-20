/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cosine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:58:21 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/08 15:00:02 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear.h"

float	cosine(const t_vector3d v1,
		const t_vector3d v2)
{
	return (dot_product(v1, v2) / sqrt(sqr_module(v1) * sqr_module(v2)));
}

float	angle(const t_vector3d v1,
		const t_vector3d v2)
{
	return (acos(cosine(v1, v2)));
}
