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
	while (ft_isspace(line[idx]))
		idx++;
	if (ft_strlen(line) == idx)
		return (true);
	return (false);
}

bool	double_check(t_cud *cud)
{
	int	i;
	int	len;
	int	total;

	i = -1;
	total = 0;
	while (cud->data[++i])
	{
		len = ft_strlen(cud->data[i]);
		if (ft_strnstr(cud->data[i], "NO", len))
			total++;
		else if (ft_strnstr(cud->data[i], "EA", len))
			total++;
		else if (ft_strnstr(cud->data[i], "SO", len))
			total++;
		else if (ft_strnstr(cud->data[i], "WE", len))
			total++;
		else if (ft_strchr(cud->data[i], 'F'))
			total++;
		else if (ft_strchr(cud->data[i], 'C'))
			total++;
	}
	if (total > 6)
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
