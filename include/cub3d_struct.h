/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:46:59 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/28 13:08:59 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include <stdbool.h>

/**
 * @brief Indexes for Cub3D.
 * NO/EA/SO/WE : Wall textures.
 * F/C : Floor/Ceiling.
 * R/G/B : Color channels.
 * X/Y/Z : Coordinates.
 * N/E/S/W : Player facing.
 * BG/WA/ME : Mini-map (background, wall, player).
 */

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
	B,
	X = 0,
	Y,
	Z,
	N = 0,
	E,
	S,
	W,
	BG = 0,
	WA,
	ME
};

/**
 * @brief Color set for parsing the .cub file.
 * c_set: Original line from file.
 * colors: Split values from c_set (by comma (,)).
 */
typedef struct s_cset
{
	char	**colors;
	char	*c_set;
} t_cset;

/**
 * @brief 3D coordinate.
 * x, y, z: Position in 3D space.
 */
typedef struct s_coordinate{
    int     x;
    int     y;
    int     z;
}   t_coordinate;

/**
 * @brief Angle data for camera or object.
 * coord: Rotation angles (x, y, z).
 * zoom: Zoom level.
 */
typedef struct s_angles
{
    int coord[3];
    int zoom;
}   t_angles;

/**
 * @brief Camera data.
 * coord: Position of the camera.
 * angle: Orientation and zoom.
 */
typedef struct s_camera
{
    int			coord[3];
    t_angles	angle;
}   t_camera;

/**
 * @brief Texture image data.
 * xpm_file: Pointer to the loaded image.
 * img_width, img_height: Dimensions of the image.
 */
typedef struct s_xpm
{
	void	*xpm_file;
	int		img_width;
	int		img_height;
} t_xpm;

/**
 * @brief Main map data.
 * title: Name of the map.
 * fc_colors: Floor and ceiling colors.
 * valid_map: Whether the map is valid.
 * points: 2D array of map points (coordinates).
 * xpms: Array of wall textures.
 */
typedef struct s_map
{
	const char		*title;
	int				fc_colors[2][3];
	bool			valid_map;
	t_coordinate    **points;
	t_xpm			xpms[4];
} t_map;

/**
 * @brief Mini-map data.
 * width, height: Mini-map size.
 * m_colors: Colors for background, wall, player.
 * title: Optional mini-map title.
 * show_slowmo_shoot: Whether slow motion shooting is shown.
 */
typedef struct s_minimap
{
    int				width;
    int				height;
	int				m_colors[3][3];
    const char		*title;
    const bool      show_slowmo_shoot;
}   t_minimap;

/**
 * @brief Temporary parsing data from .cub file.
 * dirs: Texture paths for walls.
 * data: Raw lines from the .cub file.
 * cub_fd: File descriptor for the .cub file.
 * dub: Array used for double-checking duplicates.
 * cs: Floor and ceiling color sets.
 */
typedef struct s_par
{
	char	*dirs[4];
	char	**data;
	int		cub_fd;
	int		dub[7];
	int		id_idx[7];
	t_cset	cs[2];
} t_par;

/**
 * @brief Central Cub3D data.
 * mlx: Pointer to MLX instance.
 * win: Pointer to MLX window.
 * par: Temporary parsing data.
 * map: Map data.
 * cam: Camera data.
 * minimap: Mini-map data.
 */
typedef struct s_cud
{
	void		*mlx;
	void		*win;
	t_par		par;
	t_map		map;
	t_camera	cam;
	t_minimap	minimap;
} t_cud;

#endif
