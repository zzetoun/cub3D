/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utili.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:43:28 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/26 15:43:32 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_array(char **array, int idx)
{
	if (!array)
		return ;
	while (array[idx])
	{
		free(array[idx]);
		array[idx] = NULL;
		idx++;
	}
	free(array);
	array = NULL;
}

bool	errmsg(char *details, char *error)
{
	if (details && error)
		ft_printf(2, "Error\n< %s: %s >\n", details, error);
	else if (details)
		ft_printf(2, "Error\n< %s >\n", details);
	else
		ft_printf(2, "Error\n");
	return (EXIT_FAILURE);
}
