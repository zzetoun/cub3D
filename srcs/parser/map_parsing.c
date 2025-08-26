/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:11:35 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/26 16:40:09 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	fill_to_map(t_cud *cud)
{
	int		i;
	int		j;

	i = -1;
	while (cud->data[++i])
	{
		j = 0;
		while (cud->data[i] && line_is_space(cud->data[i]))
			i++;
		if (!cud->data[i])
			return (dir_to_xpm(cud));
		while (cud->data[i] && ft_isspace((unsigned char)cud->data[i][j]))
			j++;
		if (!cud->data[i] || ft_strlen(cud->data[i]) - j < 7)
			continue ;
		if (!ft_strncmp(cud->data[i] + j, "NO ", 3) && !cud->dirs[NO])
			cud->dirs[NO] = ft_strtrim(cud->data[i] + j + 3, WHITESPACE);
		if (!ft_strncmp(cud->data[i] + j, "EA ", 3) && !cud->dirs[EA])
			cud->dirs[EA] = ft_strtrim(cud->data[i] + j + 3, WHITESPACE);
		if (!ft_strncmp(cud->data[i] + j, "SO ", 3) && !cud->dirs[SO])
			cud->dirs[SO] = ft_strtrim(cud->data[i] + j + 3, WHITESPACE);
		if (!ft_strncmp(cud->data[i] + j, "WE ", 3) && !cud->dirs[WE])
			cud->dirs[WE] = ft_strtrim(cud->data[i] + j + 3, WHITESPACE);
	}
	return (dir_to_xpm(cud));
}