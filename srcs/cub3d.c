/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:56:01 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/16 12:36:59 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_cud	cud;
	t_map	map;

	if (ac == 2)
	{
		ft_memset(&cud, '\0', sizeof(cud));
		ft_memset(&map, '\0', sizeof(map));
		cud.map = &map;
		if (file_pasring(av[1], &cud))
			return(EXIT_FAILURE);
	}
	else
		return (errmsg(ARGERR, NULL));
	return (0);
}
