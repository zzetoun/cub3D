/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:07:41 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/28 18:13:32 by zzetoun          ###   ########.fr       */
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

void	double_parsing(t_cud *cud, char *data, int len)
{
	if (data[0] == 'N' && ft_strnstr(data, "NO", len))
		cud->par.dub[NO]++;
	else if (data[0] == 'S' && ft_strnstr(data, "EA", len))
		cud->par.dub[EA]++;
	else if (data[0] == 'S' && ft_strnstr(data, "SO", len))
		cud->par.dub[SO]++;
	else if (data[0] == 'W' && ft_strnstr(data, "WE", len))
		cud->par.dub[WE]++;
	else if (data[0] == 'F')
		cud->par.dub[F + 4]++;
	else if (data[0] == 'C')
		cud->par.dub[C + 4]++;
	else if (data[0] == '1')
	{
		if (ft_strchr(data, 'N') || ft_strchr(data, 'E'))
			cud->par.dub[6]++;
		else if (ft_strchr(data, 'S') || ft_strchr(data, 'W'))
			cud->par.dub[6]++;
	}
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
