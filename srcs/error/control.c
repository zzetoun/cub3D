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

void	ft_free_array(char **array)
{
	int	idx;

	if (!array)
		return ;
	idx = -1;
	while (array[++idx])
	{
		free(array[idx]);
		array[idx] = NULL;
	}
	free(array);
	array = NULL;
}

static void	free_dirs(t_dir *dirs)
{
	if (dirs->no_dir)
		free(dirs->no_dir);
	if (dirs->so_dir)
		free(dirs->so_dir);
	if (dirs->ea_dir)
		free(dirs->ea_dir);
	if (dirs->we_dir)
		free(dirs->we_dir);
}
static void	free_xpms(t_cud *cud)
{
	int	i;

	i = -1;
	while(++i < 4)
	{
		if (cud->xpms[i].xpm_dir)
            mlx_destroy_image(cud->mlx, cud->xpms[i].xpm_dir);
	}
}

void	freedom(t_cud *cud)
{
	if (cud->file_fd > 0)
	{
		close(cud->file_fd);
		cud->file_fd = -1;
	}
	ft_free_array(cud->file_data);
	free_dirs(&cud->map.dirs);
	free_xpms(cud);
	if (cud->mlx)
		free(cud->mlx);
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
