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

static	bool	color_to_int(t_cud *cud)
{
	int		idx;
	int		jdx;

	idx = -1;
	while (++idx < 2)
	{
		jdx = -1;
		while (++jdx < 3)
		{
			if (ft_strlen(cud->cs[idx].colors[jdx]) > 3 && idx == F)
				return (errmsg(COLOROUT, "Floor"));
			else if (ft_strlen(cud->cs[idx].colors[jdx]) > 3 && idx == C)
				return (errmsg(COLOROUT, "Ceiling"));
			cud->map.colors[idx][jdx] = ft_atoi(cud->cs[idx].colors[jdx]);
		}
	}
	return (EXIT_SUCCESS);
}

static	bool	colors_clean_up(t_cud *cud)
{
	int		idx;
	int		jdx;
	char	*trim;

	idx = -1;
	while (++idx < 2)
	{
		cud->cs[idx].colors = ft_split(cud->cs[idx].c_set, ',');
		if (!cud->cs[idx].colors)
			return (errmsg(MALLERR, NULL));
		jdx = -1;
		while (++jdx < 3)
		{
			trim = ft_strtrim(cud->cs[idx].colors[jdx], WHITESPACE);
			free(cud->cs[idx].colors[jdx]);
			cud->cs[idx].colors[jdx] = ft_strdup(trim);
			free(trim);
		}
	}
	if (ft_array_len(cud->cs[F].colors) != 3)
		return (errmsg(COLORERR, "Floor"));
	if (ft_array_len(cud->cs[C].colors) != 3)
		return (errmsg(COLORERR, "Ceiling"));
	return (color_to_int(cud));
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
		if (!cud->data[i] || ft_strlen(cud->data[i]) - j < 7)
			continue ;
		if (!ft_strncmp(cud->data[i] + j, "F ", 2) && !cud->cs[F].c_set)
			cud->cs[F].c_set = ft_strtrim(cud->data[i] + j + 2, WHITESPACE);
		if (!ft_strncmp(cud->data[i] + j, "C ", 2) && !cud->cs[C].c_set)
			cud->cs[C].c_set = ft_strtrim(cud->data[i] + j + 2, WHITESPACE);
	}
	i = -1;
	while (++i < 2)
	{
		if (!cud->cs[i].c_set && i == F)
			return (errmsg(COLORNULL, "Floor"));
		else if (!cud->cs[i].c_set && i == C)
			return (errmsg(COLORNULL, "Celing"));
	}
	return (colors_clean_up(cud));
}
