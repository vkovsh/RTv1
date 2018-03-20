/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:09:42 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/12 17:15:48 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_material		material(const float ka,
		const float kd,
		const float ks,
		const float kr,
		const float kt,
		const float p)
{
	float		sum;
	t_material	m;

	sum = ka + kd + ks + kr + kt;
	m.ka = ka / sum;
	m.kd = kd / sum;
	m.ks = ks / sum;
	m.kr = kr / sum;
	m.kt = kt / sum;
	m.p = p;
	return (m);
}
