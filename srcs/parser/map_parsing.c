/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:11:35 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/30 01:53:23 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"



static	bool	valid_elements(t_cud *cud)
{
	int		idx;
	int		jdx;
	char	*line;

	idx = -1;
	while (cud->par.data[++idx])
	{
		while (cud->par.data[idx] && line_is_space(cud->par.data[idx]))
			idx++;
		line = cud->par.data[idx];
		if (!line)
			return (EXIT_SUCCESS);
		jdx = 0;
		while (line[jdx] && ft_isspace(line[jdx]))
			jdx++;
		if (line[jdx] && elements_check(line + jdx))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static	bool	find_and_validate_player(t_cud *cud)
{
	char	*line;

	cud->map.pl.facing = -1;
	while (cud->par.data[cud->map.pl.idx])
	{
		line = cud->par.data[cud->map.pl.idx];
		if (ft_strchr(line, '1') || ft_strchr(line, '0'))
		{
			if (ft_strchr(line, 'N'))
				cud->map.pl.facing = N;
			else if (ft_strchr(line, 'E'))
				cud->map.pl.facing = E;
			else if (ft_strchr(line, 'S'))
				cud->map.pl.facing = S;
			else if (ft_strchr(line, 'W'))
				cud->map.pl.facing = W;
			if (cud->map.pl.facing != -1)
				break ;
		}
		cud->map.pl.idx++;
	}
	if (cud->map.pl.facing == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static	bool	single_map(t_cud *cud)
{
	int	idx;
	int	s_idx;

	idx = cud->map.pl.idx;
	s_idx = -1;
	while (cud->par.data[idx])
	{
		if (s_idx == -1 && line_is_space(cud->par.data[idx]))
		{
			s_idx = idx;
			while (cud->par.data[s_idx] && line_is_space(cud->par.data[s_idx]))
				s_idx++;
		}
		idx++;
	}
	if (s_idx == -1)
		return (EXIT_SUCCESS);
	else if (idx - s_idx > 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static	bool	map_pos(t_cud *cud)
{
	int idx;
	int	id;
	int	map_id;

	idx = -1;
	map_id = cud->map.pl.idx;
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

bool	validate_map(t_cud *cud)
{
	cud->map.pl.idx = scan_identifier(cud, -1);
	if (cud->map.pl.idx == -1)
		return (errmsg(MAPERR, "Map Not found"));
	if (map_pos(cud))
		return (EXIT_FAILURE);
	if (valid_elements(cud))
		return (errmsg(MAPERR, "Map has illegal elements"));
	if (single_map(cud))
		return (errmsg(MAPERR, "there is more than 1 map"));
	if (find_and_validate_player(cud))
		return (errmsg(MAPERR, "Player Does not exists"));
	// if (valid_elements(cud) || fill_map(cud, map_id))
	// 	return (errmsg(MAPERR, NULL));
	return (EXIT_SUCCESS);
}
