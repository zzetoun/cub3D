/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:58:11 by zzetoun           #+#    #+#             */
/*   Updated: 2025/09/04 20:58:11 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	line_counter(t_cud *cud)
{
	char	*tmp;
	int		counter;

	tmp = gnl(cud->par.cub_fd);
	if (!tmp)
	{
		errmsg(FILEEMPTY, NULL);
		return (0);
	}
	counter = 1;
	while (tmp)
	{
		free(tmp);
		tmp = NULL;
		tmp = gnl(cud->par.cub_fd);
		if (tmp)
			counter++;
	}
	return (counter);
}

bool	double_check(t_cud *cud)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	while (cud->par.data[++i])
	{
		j = 0;
		line = cud->par.data[i];
		if (!line)
			break ;
		while (ft_isspace(line[j]))
			j++;
		double_parsing(cud, line + j, ft_strlen(line) - j);
	}
	i = -1;
	while (++i < 7)
		if (cud->par.dub[i] > 1)
			return (dc_errmsg(i));
	return (EXIT_SUCCESS);
}

bool	file_to_data(t_cud *cud, char *av)
{
	int		counter;
	int		idx;

	counter = line_counter(cud);
	if (!counter)
		return (EXIT_FAILURE);
	cud->par.data = ft_calloc(counter + 1, sizeof(char *));
	if (!cud->par.data)
		return (errmsg(MALLERR, NULL));
	if (open_file(av, cud))
		return (EXIT_FAILURE);
	idx = 0;
	while (idx < counter)
	{
		cud->par.data[idx++] = gnl(cud->par.cub_fd);
		if (!cud->par.data[idx])
			return (errmsg(MALLERR, NULL));
	}
	cud->par.data[idx] = NULL;
	return (EXIT_SUCCESS);
}

bool	file_parsing(char *av, t_cud *cud)
{
	if (!av || !av[0])
		return (errmsg(INPERR, NULL));
	if (file_format(av, ".cub"))
		return (EXIT_FAILURE);
	if (open_file(av, cud))
		return (EXIT_FAILURE);
	if (file_to_data(cud, av) || validate_map(cud) || double_check(cud))
		return (EXIT_FAILURE);
	if (fill_to_xpm(cud) || fill_to_color(cud))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
