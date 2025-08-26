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

static bool	xpm_to_image(t_cud *cud)
{
	cud->map.xpms[NO].xpm_file = mlx_xpm_file_to_image(cud->mlx, cud->dirs[NO],
			&cud->map.xpms[NO].img_width, &cud->map.xpms[NO].img_height);
	if (!cud->map.xpms[NO].xpm_file)
		return (errmsg(XPMERR, "North XPM"));
	cud->map.xpms[EA].xpm_file = mlx_xpm_file_to_image(cud->mlx, cud->dirs[EA],
			&cud->map.xpms[EA].img_width, &cud->map.xpms[EA].img_height);
	if (!cud->map.xpms[EA].xpm_file)
		return (errmsg(XPMERR, "East XPM"));
	cud->map.xpms[SO].xpm_file = mlx_xpm_file_to_image(cud->mlx, cud->dirs[SO],
			&cud->map.xpms[SO].img_width, &cud->map.xpms[SO].img_height);
	if (!cud->map.xpms[SO].xpm_file)
		return (errmsg(XPMERR, "South XPM"));
	cud->map.xpms[WE].xpm_file = mlx_xpm_file_to_image(cud->mlx, cud->dirs[WE],
			&cud->map.xpms[WE].img_width, &cud->map.xpms[WE].img_height);
	if (!cud->map.xpms[WE].xpm_file)
		return (errmsg(XPMERR, "West XPM"));
	return (EXIT_SUCCESS);
}

static	bool	dir_to_xpm(t_cud *cud)
{
	int	idx;
	int	fd;

	idx = -1;
	if (!cud->dirs[NO])
		return (errmsg(DIRNULL, "North"));
	else if (!cud->dirs[EA])
		return (errmsg(DIRNULL, "East"));
	else if (!cud->dirs[SO])
		return (errmsg(DIRNULL, "South"));
	else if (!cud->dirs[WE])
		return (errmsg(DIRNULL, "West"));
	while (++idx < 4)
	{
		if (file_format(cud->dirs[idx], ".xpm"))
			return (EXIT_FAILURE);
		fd = open(cud->dirs[idx], O_RDONLY);
		if (fd < 0)
			return (errmsg(cud->dirs[idx], strerror(errno)));
		close(fd);
	}
	if (xpm_to_image(cud))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool	fill_to_xpm(t_cud *cud)
{
	int		i;
	int		j;

	i = -1;
	while (cud->data[++i])
	{
		j = 0;
		while (cud->data[i] && line_is_space(cud->data[i]))
			i++;
		while (cud->data[i] && ft_isspace(cud->data[i][j]))
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
