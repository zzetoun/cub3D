/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:07:41 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/25 19:07:41 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	line_is_space(char *line)
{
	size_t	idx;

	if (!line)
		return (false);
	idx = 0;
	while (ft_isspace((unsigned char)line[idx]))
		idx++;
	if (ft_strlen(line) == idx)
		return (true);
	return (false);
}

bool	double_check(t_cud *cud)
{
	int		i;
	int		len;
	char	*d;

	i = -1;
	while (cud->par.data[++i])
	{
		d = cud->par.data[i];
		len = ft_strlen(d);
		cud->par.dub[0] += (ft_strnstr(d, "NO", len) != 0);
		cud->par.dub[1] += (ft_strnstr(d, "EA", len) != 0);
		cud->par.dub[2] += (ft_strnstr(d, "SO", len) != 0);
		cud->par.dub[3] += (ft_strnstr(d, "WE", len) != 0);
		cud->par.dub[4] += (ft_strchr(d, 'F') != 0);
		cud->par.dub[5] += (ft_strchr(d, 'C') != 0);
		cud->par.dub[6] += (ft_strchr(d, '1') != 0 && ft_strchr(d, 'N') != 0);
		cud->par.dub[6] += (ft_strchr(d, '1') != 0 && ft_strchr(d, 'E') != 0);
		cud->par.dub[6] += (ft_strchr(d, '1') != 0 && ft_strchr(d, 'S') != 0);
		cud->par.dub[6] += (ft_strchr(d, '1') != 0 && ft_strchr(d, 'W') != 0);
	}
	i = -1;
	while (++i < 7)
		if (cud->par.dub[i] > 1)
			return (errmsg(FILDUB, NULL));
	return (EXIT_SUCCESS);
}

bool	file_format(char *file, char *format)
{
	int	idx;

	idx = ft_strlen(file) - ft_strlen(format);
	if (idx < 0)
		return (errmsg(FILTYPE, format));
	if (!str_compare(format, file + idx))
		return (errmsg(FILNAME, format));
	return (EXIT_SUCCESS);
}
