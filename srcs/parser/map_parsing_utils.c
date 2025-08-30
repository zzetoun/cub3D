/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 00:21:44 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/30 19:12:14 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

bool	clean_up_empty_lines(t_cud *cud)
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

bool	elements_check(char *line)
{
	int	len;
	int	idx;

	len = ft_strlen(line);
	idx = 0;
	if (len == 1 && (*line != '1' || *line != '0'))
		return (EXIT_FAILURE);
	if (*line == '1' || *line == '0')
	{
		while (line[idx] && (line[idx] == '1' || line[idx] == '0'
				|| line[idx] == 'N' || line[idx] == 'W' || line[idx] == 'S'
				|| line[idx] == 'E'))
			idx++;
		while (ft_isspace(line[idx]))
			idx++;
		if (line[idx] != '\0')
			return (EXIT_FAILURE);
	}
	else if (!(ft_strnstr(line, "NO", len) || ft_strnstr(line, "EA", len)
			|| ft_strnstr(line, "SO", len) || ft_strnstr(line, "WE", len)
			|| ft_strnstr(line, "F ", len) || ft_strnstr(line, "C ", len)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool	is_map(char *line)
{
	int		idx;

	idx = 0;
	while (line[idx] && ft_isspace(line[idx]))
		idx++;
	if (line[idx] && (line[idx] == '0' || line[idx] == '1'))
		return (true);
	return (false);
}

int	scan_identifier(t_cud *cud, int i)
{
	int	len;

	cud->par.id_idx[6] = -1;
	while (cud->par.data[++i])
	{
		len = ft_strlen(cud->par.data[i]);
		if (ft_strnstr(cud->par.data[i], "NO", len))
			cud->par.id_idx[NO] = i;
		else if (ft_strnstr(cud->par.data[i], "EA", len))
			cud->par.id_idx[EA] = i;
		else if (ft_strnstr(cud->par.data[i], "SO", len))
			cud->par.id_idx[SO] = i;
		else if (ft_strnstr(cud->par.data[i], "WE", len))
			cud->par.id_idx[WE] = i;
		else if (ft_strnstr(cud->par.data[i], "F", len))
			cud->par.id_idx[F + 4] = i;
		else if (ft_strnstr(cud->par.data[i], "C", len))
			cud->par.id_idx[C + 4] = i;
		else if (cud->par.id_idx[6] == -1 && is_map(cud->par.data[i]))
			cud->par.id_idx[6] = i;
	}
	return (cud->par.id_idx[6]);
}
