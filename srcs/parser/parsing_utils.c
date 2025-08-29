/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:07:41 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/30 02:03:09 by zzetoun          ###   ########.fr       */
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
	if (!data)
		return ;
	if (data[0] == 'N' && ft_strnstr(data, "NO", len))
		cud->par.dub[NO]++;
	else if (data[0] == 'E' && ft_strnstr(data, "EA", len))
		cud->par.dub[EA]++;
	else if (data[0] == 'S' && ft_strnstr(data, "SO", len))
		cud->par.dub[SO]++;
	else if (data[0] == 'W' && ft_strnstr(data, "WE", len))
		cud->par.dub[WE]++;
	else if (data[0] == 'F' && ft_strnstr(data, "F", len))
		cud->par.dub[F + 4]++;
	else if (data[0] == 'C' && ft_strnstr(data, "C", len))
		cud->par.dub[C + 4]++;
	else if (ft_strchr(data, '1') || ft_strchr(data, '0'))
	{
		if (ft_strchr(data, 'N') || ft_strchr(data, 'E')
			|| ft_strchr(data, 'S') || ft_strchr(data, 'W'))
			cud->par.dub[6]++;
	}
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
