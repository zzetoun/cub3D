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

static	bool	clean_and_valid_dir(char **dir_ptr)
{
	char	*trimmed_dir;
	int		fd;

	trimmed_dir = ft_strtrim(*dir_ptr, WHITESPACE);
	if (!trimmed_dir)
		return (errmsg(MALLERR, NULL));
	if (file_format(trimmed_dir, ".xpm"))
	{
		free(trimmed_dir);
		return (EXIT_FAILURE);
	}
	fd = open(trimmed_dir, O_RDONLY);
	if (fd < 0)
	{
		errmsg(trimmed_dir, strerror(errno));
		free(trimmed_dir);
		return (EXIT_FAILURE);
	}
	close(fd);
	free(*dir_ptr);
	*dir_ptr = trimmed_dir;
	return (EXIT_SUCCESS);
}

static	bool	dir_to_xpm(t_cud *cud)
{
	int	idx;

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
		if (clean_and_valid_dir(&cud->dirs[idx].dir))
			return (EXIT_FAILURE);
	if (xpm_to_image(cud))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

bool	fill_to_xpm(t_cud *cud)
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
			if (!ft_strncmp(f_data + jdx, "NO", 2) && !cud->dirs[NO].dir)
				cud->dirs[NO].dir = ft_strdup(f_data + jdx + 2);
			if (!ft_strncmp(f_data + jdx, "EA", 2) && !cud->dirs[EA].dir)
				cud->dirs[EA].dir = ft_strdup(f_data + jdx + 2);
			if (!ft_strncmp(f_data + jdx, "SO", 2) && !cud->dirs[SO].dir)
				cud->dirs[SO].dir = ft_strdup(f_data + jdx + 2);
			if (!ft_strncmp(f_data + jdx, "WE", 2) && !cud->dirs[WE].dir)
				cud->dirs[WE].dir = ft_strdup(f_data + jdx + 2);
		}
	}
	return (dir_to_xpm(cud));
}
