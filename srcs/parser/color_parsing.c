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
		trimmed_dir = ft_strtrim(colors[idx], WHITESPACE);
		if (!trimmed_dir)
			return (errmsg(MALLERR, NULL));
		free(colors[idx]);
		colors[idx] = ft_strdup(trimmed_dir);
		if (!colors[idx])
		{
			ft_free_array(colors, idx);
			free(trimmed_dir);
			return (errmsg(MALLERR, NULL));
		}
		free(trimmed_dir);
	}
	return (EXIT_SUCCESS);
}

static	bool	colors_to_int(t_cud *cud)
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
			if (idx == 0)
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

static	bool	clean_up_colors(t_cud *cud)
{
	int		idx;
	char	*trimmed_dir;

	idx = -1;
	while (++idx < 2)
	{
		if (!cud->colors_data[idx])
		{
			if (idx == F)
				return (errmsg(COLORNULL, "Floor"));
			else if (idx == C)
				return (errmsg(COLORNULL, "Celing"));
		}
		trimmed_dir = ft_strtrim(cud->colors_data[idx], WHITESPACE);
		if (!trimmed_dir)
			return (errmsg(MALLERR, NULL));
		free(cud->colors_data[idx]);
		cud->colors_data[idx] = ft_strdup(trimmed_dir);
		free(trimmed_dir);
		if (!cud->colors_data[idx])
			return (errmsg(MALLERR, NULL));
	}
	if (colors_to_int(cud))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool	fill_to_color(t_cud *cud)
{
	int		idx;
	int		jdx;
	char	*f_data;

	idx = -1;
	while (cud->file_data[++idx])
	{
		jdx = 0;
		f_data = cud->file_data[idx];
		while (f_data && ft_isspace(f_data[jdx]))
			jdx++;
		if (f_data && ft_strlen(f_data) - jdx >= 7)
		{
			if (!ft_strncmp(f_data + jdx, "F ", 2) && !cud->colors_data[F])
				cud->colors_data[F] = ft_strdup(f_data + jdx + 2);
			if (!ft_strncmp(f_data + jdx, "C ", 2) && !cud->colors_data[C])
				cud->colors_data[C] = ft_strdup(f_data + jdx + 2);
		}
	}
	return (clean_up_colors(cud));
}
