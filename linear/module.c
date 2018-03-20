/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:00:39 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/08 15:01:33 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear.h"

float	sqr_module(const t_vector3d v)
{
	return (dot_product(v, v));
}

float	module(const t_vector3d v)
{
	return (sqrt(sqr_module(v)));
}
