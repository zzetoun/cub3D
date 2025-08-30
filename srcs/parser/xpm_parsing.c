/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:07:04 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/30 18:46:29 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

static bool	xpm_to_image(t_cud *cud)
{
	t_par	par;

	par = cud->par;
	cud->map.xpms[NO].xpm_file = mlx_xpm_file_to_image(cud->mlx, par.dirs[NO],
			&cud->map.xpms[NO].img_width, &cud->map.xpms[NO].img_height);
	if (!cud->map.xpms[NO].xpm_file)
		return (errmsg(XPMERR, "North XPM"));
	cud->map.xpms[EA].xpm_file = mlx_xpm_file_to_image(cud->mlx, par.dirs[EA],
			&cud->map.xpms[EA].img_width, &cud->map.xpms[EA].img_height);
	if (!cud->map.xpms[EA].xpm_file)
		return (errmsg(XPMERR, "East XPM"));
	cud->map.xpms[SO].xpm_file = mlx_xpm_file_to_image(cud->mlx, par.dirs[SO],
			&cud->map.xpms[SO].img_width, &cud->map.xpms[SO].img_height);
	if (!cud->map.xpms[SO].xpm_file)
		return (errmsg(XPMERR, "South XPM"));
	cud->map.xpms[WE].xpm_file = mlx_xpm_file_to_image(cud->mlx, par.dirs[WE],
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
	if (!cud->par.dirs[NO])
		return (errmsg(DIRNULL, "North"));
	else if (!cud->par.dirs[EA])
		return (errmsg(DIRNULL, "East"));
	else if (!cud->par.dirs[SO])
		return (errmsg(DIRNULL, "South"));
	else if (!cud->par.dirs[WE])
		return (errmsg(DIRNULL, "West"));
	while (++idx < 4)
	{
		if (file_format(cud->par.dirs[idx], ".xpm"))
			return (EXIT_FAILURE);
		fd = open(cud->par.dirs[idx], O_RDONLY);
		if (fd < 0)
			return (errmsg(cud->par.dirs[idx], strerror(errno)));
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
	while (cud->par.data[++i])
	{
		j = 0;
		while (ft_isspace((unsigned char)cud->par.data[i][j]))
			j++;
		if (!cud->par.data[i] || ft_strlen(cud->par.data[i]) - j < 7)
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
