/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:44:06 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/25 00:17:50 by zzetoun          ###   ########.fr       */
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
	array = NULL;
}

static void	free_dirs(t_cud *cud)
{
	int	idx;

	idx = -1;
	while(++idx < 4)
		if (cud->dirs[idx].dir)
            free(cud->dirs[idx].dir);
}
static void	free_xpms(t_cud *cud)
{
	int	idx;

	idx = -1;
	while(++idx < 4)
		if (cud->xpms[idx].xpm_file)
            mlx_destroy_image(cud->mlx, cud->xpms[idx].xpm_file);
}

void	freedom(t_cud *cud)
{
	if (cud->file_fd > 0)
	{
		close(cud->file_fd);
		cud->file_fd = -1;
	}
	ft_free_array(cud->data, 0);
	free_dirs(cud);
	free_xpms(cud);
	if (cud->mlx) // have to make sure if i need this or not
		free(cud->mlx);
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
