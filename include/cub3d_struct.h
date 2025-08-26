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

enum e_index
{
	NO = 0,
	EA,
	SO,
	WE,
	F = 0,
	C,
	R = 0,
	G,
	B
};

/* Color Set Struct */
typedef struct s_cset
{
	char	**colors;
	char	*c_set;
} t_cset;

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
	t_xpm	xpms[4];
} t_map;

typedef struct s_cud
{
	void	*mlx;
	char	*dirs[4];
	char	**data;
	int		file_fd;
	t_cset	cs[2];
	t_map	map;
} t_cud;

#endif
