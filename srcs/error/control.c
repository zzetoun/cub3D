/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:44:06 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/15 17:57:37 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	errmsg(char *error)
{
	if (error)
		ft_printf(2, "cub3D Error: %s\n", error);
	else
		ft_printf(2, "cub3D Error\n");
	return (EXIT_FAILURE);
}
