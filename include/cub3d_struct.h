/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:46:59 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/16 13:24:48 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include <stdbool.h>

typedef struct s_map
{
	int		**colors;
	char	*north_dir;
	char	*south_dir;
	char	*west_dir;
	char	*east_dir;
	char	*floor_c;
	char	*celing_c;
	bool	valid_map;
	
} t_map;

typedef struct s_cud
{
	char	**file_data;
	int		file_fd;
	t_map	*map;
} t_cud;

#endif
