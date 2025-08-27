/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:11:35 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/27 16:21:28 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	fill_to_map(t_cud *cud)
{
	int		i;
	int		j;

	i = -1;
	while (cud->par.data[++i])
	{
		j = 0;
		while (cud->par.data[i] && line_is_space(cud->par.data[i]))
			i++;
		if (!cud->par.data[i])
			return (dir_to_xpm(cud));
		while (ft_isspace((unsigned char)cud->par.data[i][j]))
			j++;
		if (!cud->par.data[i][j] || ft_strlen(cud->par.data[i]) - j < 7)
			continue ;
		if (!ft_strncmp(cud->par.data[i] + j, "NO ", 3) && !cud->par.dirs[NO])
			cud->par.dirs[NO] = ft_strtrim(cud->par.data[i] + j + 3, SPACES);
		if (!ft_strncmp(cud->par.data[i] + j, "EA ", 3) && !cud->par.dirs[EA])
			cud->par.dirs[EA] = ft_strtrim(cud->par.data[i] + j + 3, SPACES);
		if (!ft_strncmp(cud->par.data[i] + j, "SO ", 3) && !cud->par.dirs[SO])
			cud->par.dirs[SO] = ft_strtrim(cud->par.data[i] + j + 3, SPACES);
		if (!ft_strncmp(cud->par.data[i] + j, "WE ", 3) && !cud->par.dirs[WE])
			cud->par.dirs[WE] = ft_strtrim(cud->par.data[i] + j + 3, SPACES);
	}
	return (dir_to_xpm(cud));
}
