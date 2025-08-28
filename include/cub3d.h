/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:44:45 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/28 17:59:56 by zzetoun          ###   ########.fr       */
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
# include "lines.h"
# include "formula.h"

bool	errmsg(char *details, char *error);
bool	dc_errmsg(int idx);
bool	file_parsing(char *av, t_cud *cud);
bool	file_format(char *file, char *format);
bool    line_is_space(char *line);
bool	fill_to_xpm(t_cud *cud);
bool	fill_to_color(t_cud *cud);
bool	double_check(t_cud *cud);
bool	validate_map_pos(t_cud *cud);

int		scan_identifier(t_cud *cud, int i);

void	ft_free_array(char **array, int idx);
void	double_parsing(t_cud *cud, char *data, int len);
void	freedom(t_cud *cud);

# define SPACES " \t\n\v\f\r"
# define INPERR "No input file provided"
# define ARGERR "Invalid number of arguments: usage ./cub3D <file_name>"
# define MALLERR "Memory allocation failed: unexpected error occurred"
# define MLXINIERR "Failed to initialize the MLX graphics library"

# define FILEEMPTY "The input file is empty"
# define FILNAME "Invalid file name for"
# define FILTYPE "Unsupported file type for"
# define FILDUB "Duplicate entry detected"

# define XPMERR "Invalid or corrupted XPM file"
# define DIRNULL "XPM directory is missing or empty for"

# define COLORERR "Invalid number of color set for"
# define COLONOTDIG "Invalid input of color set for"
# define COLORNULL "Color value is missing for"
# define COLOROUT "Color value out of range (0-255) for"

# define MAPERR "Invalid map configuration"
# define MAPCHARERR "Map contains invalid characters"
# define MAPBOUNDERR "Map is not properly surrounded by walls"
# define MAPPLAYERERR "Map must contain exactly one player starting position"
# define MAPMULTIPLAYER "Multiple player positions detected"
# define MAPEMPTYERR "Map is missing or empty"
# define MAPSPACEERR "Map contains unexpected empty spaces"

#endif
