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

enum e_cd
{
	NO = 0,
	EA,
	SO,
	WE,
	F = 0,
	C
};

/* Color Set Struct */
typedef struct s_cset
{
	int		red;
	int		green;
	int		blue;
	char	**colors;
	char	*c_set;
} t_cset;

typedef	struct s_dir
{
	char	*dir;
} t_dir;

typedef struct s_xpm
{
	void	*xpm_file;
	int		img_width;
	int		img_height;
} t_xpm;

typedef struct s_map
{
	int		colors[2][3];
	bool	valid_map;
} t_map;

typedef struct s_cud
{
	void	*mlx;
	char	**data;
	int		file_fd;
	t_cset	cs[2];
	t_map	map;
	t_dir	dirs[4];
	t_xpm	xpms[4];
} t_cud;

#endif
