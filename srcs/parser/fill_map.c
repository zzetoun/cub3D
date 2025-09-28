/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:58:19 by zzetoun           #+#    #+#             */
/*   Updated: 2025/09/28 15:11:13 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

static bool	wall_around(char c, t_cud *cud, size_t i, size_t j)
{
	char	**d;

	d = cud->map.data;
	if (c == '0')
	{
		if (i == 0 || j == 0 || j >= ft_strlen(d[i - 1])
			|| !ft_strchr(WOW, d[i - 1][j]) || i >= (size_t)cud->map.height - 1
			|| j >= ft_strlen(d[i + 1]) || !ft_strchr(WOW, d[i + 1][j])
			|| !ft_strchr(WOW, d[i][j - 1]) || j >= ft_strlen(d[i]) - 1
			|| !ft_strchr(WOW, d[i][j + 1]))
			return (EXIT_FAILURE);
	}
	else if (c == ' ')
	{
		if (i > 0 && j < ft_strlen(d[i - 1]) && !ft_strchr("1 ", d[i - 1][j]))
			return (EXIT_FAILURE);
		if (i < (size_t)cud->map.height - 1 && j < ft_strlen(d[i + 1])
			&& !ft_strchr("1 ", d[i + 1][j]))
			return (EXIT_FAILURE);
		if (j > 0 && !ft_strchr("1 ", d[i][j - 1]))
			return (EXIT_FAILURE);
		if (j < ft_strlen(d[i]) - 1 && !ft_strchr("1 ", d[i][j + 1]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static	bool	clean_and_create_map(t_cud *cud)
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
	cud->map.data[i] = NULL;
	while (--i != -1)
		if (ft_strpbrk(cud->map.data[i], COORD))
			cud->map.pl.y = i;
	while (cud->map.data[cud->map.pl.y][++i])
		if (ft_strchr(COORD, cud->map.data[cud->map.pl.y][i]))
			cud->map.pl.x = i;
	cud->map.height = ft_array_len(cud->map.data);
	return (EXIT_SUCCESS);
}

static	bool	check_map_border(t_cud *cud, char **map_tab)
{
	size_t		i;
	size_t		j;
	char		c;

	i = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			c = map_tab[i][j];
			if (c == '0' && wall_around(c, cud, i, j))
				return (EXIT_FAILURE);
			else if (ft_isspace(c) && wall_around(c, cud, i, j))
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

bool	fill_map(t_cud *cud)
{
	if (clean_and_create_map(cud))
		return (EXIT_FAILURE);
	if (cud->map.height < 3)
		return (errmsg(MAPERR, "Map is too small"));
	if (check_map_border(cud, cud->map.data))
		return (errmsg(MAPBOUNDERR, NULL));
	return (EXIT_SUCCESS);
}
