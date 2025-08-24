/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:46:59 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/25 00:11:12 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include <stdbool.h>

typedef	struct s_dir
{
	char	*no_dir;
	char	*so_dir;
	char	*we_dir;
	char	*ea_dir;
} t_dir;

typedef struct s_xpm
{
	void	*no_xpm;
	void	*so_xpm;
	void	*we_xpm;
	void	*ea_xpm;
} t_xpm;

typedef struct s_map
{
	int		**colors;
	t_dir	dirs;
	char	*floor_c;
	char	*celing_c;
	bool	valid_map;
} t_map;

typedef struct s_cud
{
	void	*mlx;
	char	**file_data;
	int		file_fd;
	t_map	map;
	t_xpm	xpms;
} t_cud;

#endif
