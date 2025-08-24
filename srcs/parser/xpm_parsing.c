/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:44:30 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/25 00:23:42 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

// static bool xpm_to_image(t_cud *cud, t_xpm *xpms)
// {
//     xpms->no_xpm = mlx_xpm_file_to_image(cud->mlx, cud->map->dirs->no_dir, )
//     return ()
// }

static bool clean_and_valid_dir(char **dir_ptr)
{
    char    *trimmed_dir;
    int     fd;
    
    trimmed_dir = ft_strtrim(*dir_ptr, WHITESPACE);
    if (!trimmed_dir)
        return (errmsg(MALLERR, NULL));
    if (file_format(trimmed_dir, ".xpm"))
    {
        free(trimmed_dir);
        return (EXIT_FAILURE);
    }
    fd = open(trimmed_dir, O_RDONLY);
    if (fd < 0)
    {
        errmsg(trimmed_dir, strerror(errno));
        free(trimmed_dir);
        return (EXIT_FAILURE);
    }
    close(fd);
    free(*dir_ptr);
    *dir_ptr = trimmed_dir;
    return (EXIT_SUCCESS);
}
static bool	dir_to_xpm(t_cud *cud, t_dir *dirs)
{
	if (!dirs->no_dir)
        return (errmsg(DIRNULL, "North"));
    else if (!dirs->so_dir)
        return (errmsg(DIRNULL, "South"));
    else if (!dirs->we_dir)
        return (errmsg(DIRNULL, "West"));
    else if (!dirs->ea_dir)
        return (errmsg(DIRNULL, "East"));
    if (clean_and_valid_dir(&dirs->no_dir))
        return (EXIT_FAILURE);
    else if (clean_and_valid_dir(&dirs->so_dir))
        return (EXIT_FAILURE);
    else if (clean_and_valid_dir(&dirs->we_dir))
        return (EXIT_FAILURE);
    else if (clean_and_valid_dir(&dirs->ea_dir))
        return (EXIT_FAILURE);
    (void) cud;
    // if (xpm_to_image(cud, cud->xpms))
    //     return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

bool	fill_to_xpm(t_cud *cud)
{
	int		idx;
	int		jdx;
	char	*f_data;

	idx = -1;
	while (cud->file_data[++idx])
	{
		jdx = 0;
		idx += line_is_space(cud->file_data[idx]);
		f_data = cud->file_data[idx];
		while (f_data && ft_isspace(f_data[jdx]))
			jdx++;
		if (f_data && ft_strlen(f_data) - jdx >= 7)
		{
            if (!ft_strncmp(f_data + jdx, "NO", 2) && !cud->map.dirs.no_dir)
                cud->map.dirs.no_dir = ft_strdup(f_data + jdx + 2);
			if (!ft_strncmp(f_data + jdx, "SO", 2) && !cud->map.dirs.so_dir)
				cud->map.dirs.so_dir = ft_strdup(f_data + jdx + 2);
			if (!ft_strncmp(f_data + jdx, "WE", 2) && !cud->map.dirs.we_dir)
				cud->map.dirs.we_dir = ft_strdup(f_data + jdx + 2);
			if (!ft_strncmp(f_data + jdx, "EA", 2) && !cud->map.dirs.ea_dir)
				cud->map.dirs.ea_dir = ft_strdup(f_data + jdx + 2);
		}
	}
    return (dir_to_xpm(cud, &cud->map.dirs));
}
