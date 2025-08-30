/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:19:32 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/30 23:48:59 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

static	bool	copy_map(t_cud *cud)
{
	int		len;
	int		i;

	len = ft_array_len(cud->par.data + cud->par.id_idx[6]);
	cud->map.data = ft_calloc(len + 1, sizeof(char *));
	if (!cud->map.data)
		return (errmsg(MALLERR, NULL));
	i = 0;
	len = cud->par.id_idx[6];
	while (cud->par.data[len])
	{
		cud->map.data[i++] = ft_strdup(cud->par.data[len++]);
		if (!cud->map.data[i - 1])
			return (errmsg(MALLERR, NULL));
	}
	cud->map.data[i] = '\0';
	while (--i != -1)
		if (ft_strpbrk(cud->map.data[i], COORD))
			cud->map.pl.y = i;
	while (cud->map.data[cud->map.pl.y][++i])
		if (ft_strchr(COORD, cud->map.data[cud->map.pl.y][i]))
			cud->map.pl.x = i;
	return (EXIT_SUCCESS);
}

bool	fill_map(t_cud *cud)
{
	if (copy_map(cud))
		return (EXIT_FAILURE);
	return (false);
}
