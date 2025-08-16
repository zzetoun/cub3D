/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:44:45 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/16 12:56:49 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_struct.h"
# include "../srcs/utils/libft/libft.h"
# include "../srcs/utils/mlx/mlx-mac/mlx.h"
# include <math.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

bool	errmsg(char *details, char *error);
bool	file_pasring(char *av, t_cud *cud);

# define ARGERR "Nubers of Arguments only 1 ./cub3D file_name"
# define INPERR "no file input"
# define MALLERR "malloc error :an unexpected error occured"
# define FILEEMPTY "file is empty"

#endif
