/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:43:44 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/26 15:43:44 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	free_colors(t_cud *cud)
{
	int	idx;

	idx = -1;
	while (++idx < 2)
	{
		if (cud->cs[idx].c_set)
		{
			free(cud->cs[idx].c_set);
			cud->cs[idx].c_set = NULL;
		}
		if (cud->cs[idx].colors)
		{
			ft_free_array(cud->cs[idx].colors, 0);
			cud->cs[idx].colors = NULL;
		}
	}
}

static void	free_dirs(t_cud *cud)
{
	int	idx;

	idx = -1;
	while (++idx < 4)
	{
		if (cud->dirs[idx])
		{
			free(cud->dirs[idx]);
			cud->dirs[idx] = NULL;
		}
	}
}

static	void	free_xpms(t_cud *cud)
{
	int	idx;

	idx = -1;
	while (++idx < 4)
	{
		if (cud->map.xpms[idx].xpm_file)
		{
			mlx_destroy_image(cud->mlx, cud->map.xpms[idx].xpm_file);
			cud->map.xpms[idx].xpm_file = NULL;
		}

	}
}

void	freedom(t_cud *cud)
{
	if (!cud)
		return ;
	if (cud->file_fd > 0)
	{
		close(cud->file_fd);
		cud->file_fd = -1;
	}
	if (cud->data)
	{
		ft_free_array(cud->data, 0);
		cud->data = NULL;
	}
	free_dirs(cud);
	free_xpms(cud);
	free_colors(cud);
}
