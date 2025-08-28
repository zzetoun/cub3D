/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:11:35 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/28 16:08:45 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

bool	validate_map_pos(t_cud *cud)
{
	int	idx;
	int	map_id;
	int	id;

	map_id = scan_identifier(cud, -1);
	if (map_id == -1)
		return (errmsg(MAPERR, "Map Not found"));
	idx = -1;
	while (++idx < 7)
	{
		id = cud->par.id_idx[idx];
		if (id != -1 && map_id < id && ft_strchr(cud->par.data[map_id], '1'))
			return (errmsg(MAPERR, "Map should be after identifiers"));
		else if (id != -1 && map_id < id)
			return (errmsg(MAPERR, NULL));
	}
	return (EXIT_SUCCESS);
}
