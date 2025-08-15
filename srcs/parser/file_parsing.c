/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:44:30 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/15 18:27:56 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	file_is_dir(char *input)
{
	(void) input;
	return (true);
}

bool	file_pasring(char *av, t_cud *cud)
{
	if(!av || !av[0])
		return(errmsg(INPERR));
	cud->input = ft_strdup(av);
	if (!cud->input)
		return(errmsg(MALLERR));
	return(EXIT_SUCCESS);
}


