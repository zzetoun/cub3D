/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:11:02 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/28 13:48:32 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

bool	file_to_data(t_cud *cud)
{
	char	*tmp;
	char	*line;

	tmp = gnl(cud->par.cub_fd);
	if (!tmp)
		return (errmsg(FILEEMPTY, NULL));
	line = NULL;
	line = ft_strjoin(line, tmp);
	while (tmp)
	{
		free(tmp);
		tmp = NULL;
		tmp = gnl(cud->par.cub_fd);
		line = ft_strjoin_free(line, tmp);
	}
	cud->par.data = ft_split(line, '\n');
	free(line);
	if (!cud->par.data)
		return (errmsg(MALLERR, NULL));
	return (EXIT_SUCCESS);
}

bool	file_parsing(char *av, t_cud *cud)
{
	if (!av || !av[0])
		return (errmsg(INPERR, NULL));
	if (file_format(av, ".cub"))
		return (EXIT_FAILURE);
	cud->par.cub_fd = open(av, O_RDONLY);
	if (cud->par.cub_fd < 0)
		return (errmsg(av, strerror(errno)));
	if (file_to_data(cud) || validate_map_pos(cud) || double_check(cud))
		return (EXIT_FAILURE);
	if (fill_to_xpm(cud) || fill_to_color(cud))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
