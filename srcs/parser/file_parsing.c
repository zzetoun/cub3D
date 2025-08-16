/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:44:30 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/16 13:00:14 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	file_is_dir(int file)
{
	char *line;

	line = gnl(file);
	if (!line)
		return (errmsg(FILEEMPTY, NULL));
	return (false);
}

bool	file_pasring(char *av, t_cud *cud)
{
	if(!av || !av[0])
		return(errmsg(INPERR, NULL));
	cud->file = open(av, O_RDONLY);
	if (cud->file < 0)
		return(errmsg(av, strerror(errno)));
	if (file_is_dir(cud->file))
		return(EXIT_FAILURE);
	return(EXIT_SUCCESS);
}


