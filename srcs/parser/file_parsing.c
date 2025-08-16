/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:44:30 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/16 17:20:08 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	file_to_data(t_cud *cud)
{
	char	*tmp;
	char	*line;

	tmp = gnl(cud->file_fd);
	if (!tmp)
		return (errmsg(FILEEMPTY, NULL));
	line = NULL;
	line = ft_strjoin(line, tmp);
	while (tmp)
	{
		free(tmp);
		tmp = NULL;
		tmp = gnl(cud->file_fd);
		line = ft_strjoin_free(line, tmp);
	}
	cud->file_data = ft_split(line, '\n');
	if(!cud->file_data)
		return(errmsg(MALLERR, NULL));
	free(line);
	return (0);
}

bool	file_pasring(char *av, t_cud *cud)
{
	int idx = -1;
	if(!av || !av[0])
		return(errmsg(INPERR, NULL));
	cud->file_fd = open(av, O_RDONLY);
	if (cud->file_fd < 0)
		return(errmsg(av, strerror(errno)));
	if (file_to_data(cud))
		return(EXIT_FAILURE);
	while(cud->file_data[++idx])
		ft_printf(1, "cud->file_data[%d] = [%s]\n", idx, cud->file_data[idx]);
	freedom(cud);
	return(EXIT_SUCCESS);
}


