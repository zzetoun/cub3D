/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:44:30 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/16 14:01:37 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	file_to_data(t_cud *cud)
{
	char	*line;
	int		counter;

	line = gnl(cud->file_fd, NULL);
	if (!line)
		return (errmsg(FILEEMPTY, NULL));
	counter = 0;
	while (line)
	{
		ft_printf(1, "line: [%s]\n", line);
		line = gnl(cud->file_fd, &line);
		counter++;
	}
	free(line);
	return (false);
}

bool	file_pasring(char *av, t_cud *cud)
{
	if(!av || !av[0])
		return(errmsg(INPERR, NULL));
	cud->file_fd = open(av, O_RDONLY);
	if (cud->file_fd < 0)
		return(errmsg(av, strerror(errno)));
	if (file_to_data(cud))
		return(EXIT_FAILURE);
	return(EXIT_SUCCESS);
}


