/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:10:17 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/24 02:16:53 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

bool	line_is_space(char *line)
{
	size_t	idx;
	
	if(!line)
		return(false);
	idx = 0;
	while(ft_isspace(line[idx]))
		idx++;
	if (ft_strlen(line) == idx + 1)
		return(true);
	return(false);
}

bool	file_format(char *file, char *format)
{
	int	i;

	i = ft_strlen(file) - 4;
	if (i < 0)
		return (errmsg(FILTY, format));
	if(!str_compare(format, file + i))
		return (errmsg(FILNM, format));
	return (false);
}
