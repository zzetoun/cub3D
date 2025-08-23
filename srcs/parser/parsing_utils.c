/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:10:17 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/24 00:35:41 by zzetoun          ###   ########.fr       */
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
