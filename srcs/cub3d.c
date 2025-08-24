/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:56:01 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/25 00:20:50 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_cud	cud;
	
	if (ac != 2)
		return (errmsg(ARGERR, NULL));
	ft_memset(&cud, '\0', sizeof(cud));
	cud.mlx = mlx_init();
	if (!cud.mlx)
		return (errmsg(MLXINIERR, NULL));
	if (file_pasring(av[1], &cud))
	{
		freedom(&cud);
		return(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
