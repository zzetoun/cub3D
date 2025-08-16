/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:44:06 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/16 13:21:43 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	freedom(t_cud *cud)
{
	if (cud && cud->file_fd > 0)
	{
		close(cud->file_fd);
		cud->file_fd = -1;
	}
}

bool	errmsg(char *details, char *error)
{
	if (details && error)
		ft_printf(2, "Error\n<%s: %s>\n", details, error);
	else if (details)
		ft_printf(2, "Error\n<%s>\n", details);
	else
		ft_printf(2, "Error\n");
	return (EXIT_FAILURE);
}
