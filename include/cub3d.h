/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:44:45 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/25 00:23:54 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
bool	file_parsing(char *av, t_cud *cud);
bool	file_format(char *file, char *format);
bool    line_is_space(char *line);

bool	fill_to_xpm(t_cud *cud);
bool	fill_to_color(t_cud *cud);
void	ft_free_array(char **array, int idx);
void	freedom(t_cud *cud);

# define WHITESPACE " \t\n\v\f\r"
# define MLXINIERR "mlx failed to initlize"
# define INPERR "no file input"
# define FILEEMPTY "file is empty"
# define FILNAME "Wrong file name of"
# define FILTYPE "Wrong file type of"
# define XPMERR "XPM file is invalid of"
# define DIRNULL "XPM directory is empty to"
# define COLORERR "Color set number is wrong"
# define COLORNULL "Color set is empty"
# define ARGERR "Numbers of Arguments only 1 ./cub3D file_name"
# define MALLERR "malloc error :an unexpected error occured"

#endif
