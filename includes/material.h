/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:01:57 by vkovsh            #+#    #+#             */
/*   Updated: 2018/02/13 15:03:51 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

typedef struct	s_material
{
	float		ka;
	float		kd;
	float		ks;
	float		kr;
	float		kt;
	float		p;
}				t_material;
#endif
