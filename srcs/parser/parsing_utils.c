/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:07:41 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/28 16:08:35 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
		cud->par.dub[NO] += (ft_strnstr(d, "NO", len) != 0);
		cud->par.dub[EA] += (ft_strnstr(d, "EA", len) != 0);
		cud->par.dub[SO] += (ft_strnstr(d, "SO", len) != 0);
		cud->par.dub[WE] += (ft_strnstr(d, "WE", len) != 0);
		cud->par.dub[F + 4] += (ft_strchr(d, 'F') != 0);
		cud->par.dub[C + 4] += (ft_strchr(d, 'C') != 0);
		cud->par.dub[6] += (ft_strchr(d, '1') != 0 && ft_strchr(d, 'N') != 0);
		cud->par.dub[6] += (ft_strchr(d, '1') != 0 && ft_strchr(d, 'E') != 0);
		cud->par.dub[6] += (ft_strchr(d, '1') != 0 && ft_strchr(d, 'S') != 0);
		cud->par.dub[6] += (ft_strchr(d, '1') != 0 && ft_strchr(d, 'W') != 0);
	}
	i = -1;
	while (++i < 7)
		if (cud->par.dub[i] > 1)
			return (dc_errmsg(i));
	return (EXIT_SUCCESS);
}

int	scan_identifier(t_cud *cud, int i)
{
	int	len;

	while (cud->par.data[++i])
	{
		while (cud->par.data[i] && line_is_space(cud->par.data[i]))
			i++;
		if (!cud->par.data[i])
			return (cud->par.id_idx[6]);
		len = ft_strlen(cud->par.data[i]);
		if (ft_strnstr(cud->par.data[i], "NO", len))
			cud->par.id_idx[NO] = i;
		else if (ft_strnstr(cud->par.data[i], "EA", len))
			cud->par.id_idx[EA] = i;
		else if (ft_strnstr(cud->par.data[i], "SO", len))
			cud->par.id_idx[SO] = i;
		else if (ft_strnstr(cud->par.data[i], "WE", len))
			cud->par.id_idx[WE] = i;
		else if (ft_strnstr(cud->par.data[i], "F", len))
			cud->par.id_idx[F + 4] = i;
		else if (ft_strnstr(cud->par.data[i], "C", len))
			cud->par.id_idx[C + 4] = i;
		else if (cud->par.id_idx[6] == -1)
			cud->par.id_idx[6] = i;
	}
	return (cud->par.id_idx[6]);
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
