/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:03:28 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/27 16:26:49 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ratios_of_sides(const t_triangle *viewplane, const t_triangle *object)
{
	if (!viewplane || !object)
		return (NAN);
	return (object->y * (viewplane->z / object->z));
}
