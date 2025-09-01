/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:19:32 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/31 17:58:23 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

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
	int idx = -1;
	int jdx;
	while (cud->map.data[++idx])
	{
		// ft_printf(1, "cud->map.data[%d]=[%s]", idx, cud->map.data[idx]);
		jdx = 0;
		while (cud->map.data[idx][jdx])
		{
			if (cud->map.data[idx][jdx] != '1' && cud->map.data[idx][jdx] != '0')
				ft_printf(1, "\ncud->map.data[%d][%d]=[%d]", idx, jdx , cud->map.data[idx][jdx]);
			jdx++;
		}
	}
	return (EXIT_SUCCESS);
}

static bool	check_top_or_bottom(char **map_tab, int i, int j)
{
	if (!map_tab || !map_tab[i] || !map_tab[i][j])
		return (EXIT_FAILURE);
	while (ft_isspace(map_tab[i][j]))
		j++;
	while (map_tab[i][j])
	{
		// ft_printf(1, "map_tab[%d][%d]=[%c]\n", i,j,map_tab[i][j]);
		if (map_tab[i][j] != '1')
			return (EXIT_FAILURE);
		j++;
	}
	return (EXIT_SUCCESS);
}

static	bool	check_map_sides(t_cud *cud, char **map_tab)
{
	int	i;
	int	j;

	if (check_top_or_bottom(map_tab, 0, 0))
		return (EXIT_FAILURE);
	i = 1;
	while (i < cud->map.height - 1)
	{
		j = ft_strlen(map_tab[i]) - 1;
		// ft_printf(1, "map_tab[%d][%d]=[%c]\n", i,j,map_tab[i][j]);
		if (map_tab[i][j] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	if (check_top_or_bottom(map_tab, i, 0))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool	fill_map(t_cud *cud)
{
	if (clean_and_create_map(cud))
		return (EXIT_FAILURE);
	if (check_map_sides(cud, cud->map.data))
		return (errmsg(MAPBOUNDERR, NULL));
	return (EXIT_SUCCESS);
}
