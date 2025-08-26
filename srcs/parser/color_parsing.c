/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:07:04 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/25 19:07:04 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	bool	format_validate(char **colors)
{
	char	*trimmed_dir;
	int		idx;

	idx = -1;
	while (++idx < 3)
	{
		if (ft_strlen(color[idx] > 3))
			return (errmsg(COLOROUT, NULL));
		else 
	}

	return (EXIT_SUCCESS);
}

static	bool	colors_clean_up(t_cud *cud)
{
	char	**colors;
	int		idx;
	bool	status;

	idx = -1;
	while (++idx < 2)
	{
		colors = ft_split(cud->colors_data[idx], ',');
		if (!colors)
			return (errmsg(MALLERR, NULL));
		if (ft_array_len(colors) != 3)
		{
			ft_free_array(colors, 0);
			if (idx == F)
				return (errmsg("Floor", COLORERR));
			else
				return (errmsg("Ceiling", COLORERR));
		}
		status = format_validate(colors);
		ft_free_array(colors, 0);
		if (status)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

bool	fill_to_color(t_cud *cud)
{
	int		i;
	int		j;

	i = -1;
	while (cud->data[++i])
	{
		j = 0;
		while (cud->data[i] && ft_isspace(cud->data[i][j]))
			j++;
		if (!cud->data[i] && ft_strlen(cud->data[i]) - j < 7)
			continue;
		if (!ft_strncmp(cud->data[i] + j, "F ", 2) && !cud->cs[F].c_set)
			cud->cs[F].c_set = ft_strtrim(cud->data[i] + j + 2, WHITESPACE);
		if (!ft_strncmp(cud->data[i] + j, "C ", 2) && !cud->cs[C].c_set)
			cud->cs[c].c_set = ft_strtrim(cud->data[i] + j + 2, WHITESPACE);
	}
	if (!cud->cs[F].c_set)
		return (errmsg(COLORNULL, "Floor"));
	else if (!cud->cs[C].c_set)
		return (errmsg(COLORNULL, "Celing"));
	return (colors_clean_up(cud));
}
