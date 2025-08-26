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
	char	*dir;

	dir = cud->dirs[NO].dir;
	cud->xpms[NO].xpm_file = mlx_xpm_file_to_image(cud->mlx, dir,
			&cud->xpms[NO].img_width, &cud->xpms[NO].img_height);
	if (!cud->xpms[NO].xpm_file)
		return (errmsg(XPMERR, "North XPM"));
	dir = cud->dirs[EA].dir;
	cud->xpms[EA].xpm_file = mlx_xpm_file_to_image(cud->mlx, dir,
			&cud->xpms[EA].img_width, &cud->xpms[EA].img_height);
	if (!cud->xpms[EA].xpm_file)
		return (errmsg(XPMERR, "East XPM"));
	dir = cud->dirs[SO].dir;
	cud->xpms[SO].xpm_file = mlx_xpm_file_to_image(cud->mlx, dir,
			&cud->xpms[SO].img_width, &cud->xpms[SO].img_height);
	if (!cud->xpms[SO].xpm_file)
		return (errmsg(XPMERR, "South XPM"));
	dir = cud->dirs[WE].dir;
	cud->xpms[WE].xpm_file = mlx_xpm_file_to_image(cud->mlx, dir,
			&cud->xpms[WE].img_width, &cud->xpms[WE].img_height);
	if (!cud->xpms[WE].xpm_file)
		return (errmsg(XPMERR, "West XPM"));
	return (EXIT_SUCCESS);
}

static	bool	dir_to_xpm(t_cud *cud)
{
	int	idx;
	int	fd;

	idx = -1;
	if (!cud->dirs[NO].dir)
		return (errmsg(DIRNULL, "North"));
	else if (!cud->dirs[EA].dir)
		return (errmsg(DIRNULL, "East"));
	else if (!cud->dirs[SO].dir)
		return (errmsg(DIRNULL, "South"));
	else if (!cud->dirs[WE].dir)
		return (errmsg(DIRNULL, "West"));
	while (++idx < 4)
	{
		if (file_format(cud->dirs[idx].dir, ".xpm"))
			return (EXIT_FAILURE);
		fd = open(cud->dirs[idx].dir, O_RDONLY);
		if (fd < 0)
			return (errmsg(cud->dirs[idx].dir, strerror(errno)));
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
		while(line_is_space(cud->data[i]))
			i++;
		while (cud->data[i] && ft_isspace(cud->data[i][j]))
			j++;
		if (!cud->data[i] || ft_strlen(cud->data[i]) - j < 7)
			continue;
		if (!ft_strncmp(cud->data[i] + j, "NO ", 3) && !cud->dirs[NO].dir)
			cud->dirs[NO].dir = ft_strtrim(cud->data[i] + j + 3, WHITESPACE);
		if (!ft_strncmp(cud->data[i] + j, "EA ", 3) && !cud->dirs[EA].dir)
			cud->dirs[EA].dir = ft_strtrim(cud->data[i] + j + 3, WHITESPACE);
		if (!ft_strncmp(cud->data[i] + j, "SO ", 3) && !cud->dirs[SO].dir)
			cud->dirs[SO].dir = ft_strtrim(cud->data[i] + j + 3, WHITESPACE);
		if (!ft_strncmp(cud->data[i] + j, "WE ", 3) && !cud->dirs[WE].dir)
			cud->dirs[WE].dir = ft_strtrim(cud->data[i] + j + 3, WHITESPACE);
	}
	return (dir_to_xpm(cud));
}
