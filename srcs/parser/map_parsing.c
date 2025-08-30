/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:11:35 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/30 20:44:50 by zzetoun          ###   ########.fr       */
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

	cud->map.pl.idx = scan_identifier(cud, -1);
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
	int		idx;
	int		i;
	int		map_id;
	char	*s;

	idx = -1;
	map_id = cud->map.pl.idx;
	s = cud->par.data[cud->map.pl.idx];
	while (++idx < 7)
	{
		i = cud->par.id_idx[idx];
		if (i != -1 && map_id < i && (ft_strchr(s, '1') || ft_strchr(s, '0')))
			return (errmsg(MAPERR, "Map should be after identifiers"));
		else if (i != -1 && map_id < i)
			return (errmsg(MAPERR, NULL));
	}
	return (EXIT_SUCCESS);
}

static	bool	clean_up_empty_lines(t_cud *cud)
{
	char	**tmp;
	int		idx;
	int		jdx;

	idx = -1;
	jdx = 0;
	while (cud->par.data[++idx])
		if (line_is_space(cud->par.data[idx]))
			jdx++;
	tmp = ft_calloc(idx - jdx + 1, sizeof(char *));
	if (!tmp)
		return (EXIT_FAILURE);
	idx = -1;
	jdx = 0;
	while (cud->par.data[++idx])
	{
		if (!line_is_space(cud->par.data[idx]))
			tmp[jdx++] = ft_strdup(cud->par.data[idx]);
		if (!tmp[jdx - 1])
			return (ft_free_array(tmp, 0), EXIT_FAILURE);
	}
	tmp[jdx] = '\0';
	ft_free_array(cud->par.data, 0);
	cud->par.data = tmp;
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
		return (errmsg(MAPERR, "Map has illegal elements or not connected"));
	if (single_map(cud))
		return (errmsg(MAPERR, "there is more than 1 map"));
	if (clean_up_empty_lines(cud))
		return (errmsg(MALLERR, NULL));
	if (find_and_validate_player(cud))
		return (errmsg(MAPERR, "Player Does not exists"));
	if (fill_map(cud))
		return (errmsg(MAPERR, "FILL MAP"));
	return (EXIT_SUCCESS);
}
