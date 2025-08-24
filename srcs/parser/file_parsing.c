/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:44:30 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/24 17:11:53 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
	free(line);
	if (!cud->file_data)
		return(errmsg(MALLERR, NULL));
	return (EXIT_SUCCESS);
}

bool	file_pasring(char *av, t_cud *cud)
{
	//int idx = -1;

	if(!av || !av[0])
		return(errmsg(INPERR, NULL));
	if (file_format(av, ".cub"))
		return(EXIT_FAILURE);
	cud->file_fd = open(av, O_RDONLY);
	if (cud->file_fd < 0)
		return(errmsg(av, strerror(errno)));
	if (file_to_data(cud))
		return(EXIT_FAILURE);
	// while(cud->file_data[++idx])
	// 	ft_printf(1, "[%d]:[%s]", idx, cud->file_data[idx]);
	if(fill_dir(cud))
		return(EXIT_FAILURE);
	ft_printf(1, "no_dir: [%s]", cud->map->dirs->no_dir);
	ft_printf(1, "so_dir: [%s]", cud->map->dirs->so_dir);
	ft_printf(1, "we_dir: [%s]", cud->map->dirs->we_dir);
	ft_printf(1, "ea_dir: [%s]", cud->map->dirs->ea_dir);
	return(EXIT_SUCCESS);
}

