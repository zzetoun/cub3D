/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:07:04 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/30 18:46:44 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

static	bool	color_set_is_digit(char *color_set)
{
	int	idx;

	idx = -1;
	while (color_set[++idx])
		if (!ft_isdigit(color_set[idx]))
			return (false);
	return (true);
}

static	bool	color_to_int(t_cud *cud)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (++j < 3)
		{
			if (i == F && !color_set_is_digit(cud->par.cs[i].colors[j]))
				return (errmsg(COLONOTDIG, "Floor"));
			else if (i == C && !color_set_is_digit(cud->par.cs[i].colors[j]))
				return (errmsg(COLONOTDIG, "Floor"));
			len = ft_strlen(cud->par.cs[i].colors[j]);
			if (len > 3 && i == F)
				return (errmsg(COLOROUT, "Floor"));
			else if (len > 3 && i == C)
				return (errmsg(COLOROUT, "Ceiling"));
			cud->map.fc_colors[i][j] = ft_atoi(cud->par.cs[i].colors[j]);
		}
	}
	return (EXIT_SUCCESS);
}

static	bool	colors_clean_up(t_cud *cud)
{
	int		i;
	int		j;
	char	*trim;

	i = -1;
	while (++i < 2)
	{
		cud->par.cs[i].colors = ft_split(cud->par.cs[i].c_set, ',');
		if (!cud->par.cs[i].colors)
			return (errmsg(MALLERR, NULL));
		j = -1;
		while (++j < 3)
		{
			trim = ft_strtrim(cud->par.cs[i].colors[j], SPACES);
			free(cud->par.cs[i].colors[j]);
			cud->par.cs[i].colors[j] = ft_strdup(trim);
			free(trim);
		}
	}
	if (ft_array_len(cud->par.cs[F].colors) != 3)
		return (errmsg(COLORERR, "Floor"));
	if (ft_array_len(cud->par.cs[C].colors) != 3)
		return (errmsg(COLORERR, "Ceiling"));
	return (color_to_int(cud));
}

bool	fill_to_color(t_cud *cud)
{
	int		i;
	int		j;

	i = -1;
	while (cud->par.data[++i])
	{
		j = 0;
		while (ft_isspace((unsigned char)cud->par.data[i][j]))
			j++;
		if (!cud->par.data[i] || ft_strlen(cud->par.data[i]) - j < 7)
			continue ;
		if (!ft_strncmp(cud->par.data[i] + j, "F ", 2) && !cud->par.cs[F].c_set)
			cud->par.cs[F].c_set = ft_strtrim(cud->par.data[i] + j + 2, SPACES);
		if (!ft_strncmp(cud->par.data[i] + j, "C ", 2) && !cud->par.cs[C].c_set)
			cud->par.cs[C].c_set = ft_strtrim(cud->par.data[i] + j + 2, SPACES);
	}
	if (!cud->par.cs[F].c_set)
		return (errmsg(COLORNULL, "Floor"));
	else if (!cud->par.cs[C].c_set)
		return (errmsg(COLORNULL, "Celing"));
	return (colors_clean_up(cud));
}
