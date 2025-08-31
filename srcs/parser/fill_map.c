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
	return (EXIT_SUCCESS);
}

static	char	**copy_map(t_cud *cud)
{
	char	**copy_map;
	int		idx;
	int		len;

	cud->map.height = ft_array_len(cud->map.data);
	copy_map = ft_calloc(cud->map.height + 1, sizeof(char *));
	if (!copy_map)
		return (NULL);
	idx = -1;
	while (cud->map.data[++idx])
	{
		copy_map[idx] = ft_strdup(cud->map.data[idx]);
		if (!copy_map[idx])
		{
			ft_free_array(copy_map, 0);
			return (NULL);
		}
		len = ft_strlen(cud->map.data[idx]);
		if (cud->map.width < len)
			cud->map.width = len;
	}
	copy_map[idx] = NULL;
	return (copy_map);
}

static bool	fill_area(char **tab, int row, int col, int w, int h)
{
	if (row < 0 || col < 0 || row >= h || col >= w)
		return (EXIT_FAILURE);
	if (col >= (int)ft_strlen(tab[row]))
		return (EXIT_FAILURE);
	if (tab[row][col] == '1' || tab[row][col] == 'X')
		return (EXIT_SUCCESS);
	if (tab[row][col] == ' ')
		return (EXIT_FAILURE);
	if (tab[row][col] != '0' && tab[row][col] != 'N'
		&& tab[row][col] != 'S' && tab[row][col] != 'E'
		&& tab[row][col] != 'W')
		return (EXIT_SUCCESS);
	tab[row][col] = 'X';
	if (fill_area(tab, row - 1, col, w, h))
		return (EXIT_FAILURE);
	if (fill_area(tab, row + 1, col, w, h))
		return (EXIT_FAILURE);
	if (fill_area(tab, row, col - 1, w, h))
		return (EXIT_FAILURE);
	if (fill_area(tab, row, col + 1, w, h))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static bool	flood_fill_check(char **tab, int x, int y, int w, int h)
{
	return (fill_area(tab, y, x, w, h));
}

bool	fill_map(t_cud *cud)
{
	char	**tmp_map;

	if (clean_and_create_map(cud))
		return (EXIT_FAILURE);
	tmp_map = copy_map(cud);
	if (!tmp_map)
		return (errmsg(MALLERR, NULL));
	cud->map.valid_map = flood_fill_check(tmp_map, cud->map.pl.x,
		cud->map.pl.y, cud->map.width, cud->map.height);
	ft_free_array(tmp_map, 0);
	if (cud->map.valid_map)
		return (errmsg(MAPBOUNDERR, NULL));
	return (EXIT_SUCCESS);
}
