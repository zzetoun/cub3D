/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utili.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:43:28 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/28 15:52:35 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

bool	dc_errmsg(int idx)
{
	if (idx == NO)
		return (errmsg(FILDUB, "North Directory"));
	else if (idx == EA)
		return (errmsg(FILDUB, "East Directory"));
	else if (idx == SO)
		return (errmsg(FILDUB, "South Directory"));
	else if (idx == WE)
		return (errmsg(FILDUB, "West Directory"));
	else if (idx == F + 4)
		return (errmsg(FILDUB, "Floor Color Set"));
	else if (idx == C + 4)
		return (errmsg(FILDUB, "Celing Directory"));
	return (errmsg(FILDUB, "Player"));
}
