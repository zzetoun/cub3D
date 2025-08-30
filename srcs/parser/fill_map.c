/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:19:32 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/30 21:08:02 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

static	bool	copy_map(t_cud *cud)
{
	int	len;
	int	idx;

	len = ft_array_len(cud->par.data + cud->par.id_idx[6]);
	cud->par.map = ft_calloc(len + 1, sizeof(char *));
	if (!cud->par.map)
		return (errmsg(MALLERR, NULL));
	idx = 0;
	len = cud->par.id_idx[6];
	while (cud->par.data[len])
	{
		cud->par.map[idx++] = ft_strdup(cud->par.data[len++]);
		if (!cud->par.map[idx - 1])
			return (errmsg(MALLERR, NULL));
	}
	cud->par.map[idx] = '\0';
	return (EXIT_SUCCESS);
}

bool	fill_map(t_cud *cud)
{
	if (copy_map(cud))
		return (EXIT_FAILURE);
	return (true);
}
