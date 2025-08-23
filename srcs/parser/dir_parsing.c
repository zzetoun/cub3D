/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:44:30 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/24 01:59:28 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

static bool dir_validatio(char *dir)
{
    
}

static bool clean_and_valid_dir(char *dir)
{
    char    *tmp;
    size_t	start;
    size_t	end;

    tmp = ft_strdup(dir);
    if (!tmp)
        return(errmsg(MALLERR, NULL));
    free(dir);
    start = 0;
    while(ft_isspace(tmp[start])
        start++;
    end = ft_strlen(tmp) - 1;
    while(ft_isspace(tmp[end])
        end--;
    dir = ft_substr(tmp, star, ft_strlen(tmp) - end - start);
    free(tmp);
    if (!dir)
        return(errmsg(MALLERR, NULL));
    start = ft_strlen(dir) - 4;
	if (start < 0)
		return(errmsg(XMPFILTY, NULL));
	if(!str_compare(".xmp", dir + start))
		return(errmsg(XMPFILNM, NULL));
	return(dir_validatio(dir));
}
static bool	clean_up_dirs(t_dir *dirs)
{
	if (!dirs->no_dir || !dirs->so_dir || !dirs->we_dir || !dirs->ea_dir)
        return (false);
    if (!clean_and_valid_dir(dirs->no_dir))
        return (false);
    if (!clean_and_valid_dir(dirs->so_dir))
        return (false);
    if (!clean_and_valid_dir(dirs->we_dir))
        return (false);
    if (!clean_and_valid_dir(dirs->ea_dir))
        return (false);
    return (true);
}

bool	fill_dir(t_cud *cud)
{
	int		idx;
	int		j;
	char	*f_data;

	idx = -1;
	while (cud->file_data[++idx])
	{
		j = 0;
		idx += line_is_space(cud->file_data[idx]);
		f_data = cud->file_data[idx];
		while (f_data && ft_isspace(f_data[j]))
			j++;
		if (f_data && ft_strlen(f_data) - j >= 6)
		{
			if (!ft_strncmp(f_data + j, "NO", 2) && ft_isspace(f_data[j + 2]))
				cud->map->dirs->no_dir = ft_strdup(f_data + j + 3);
			if (!ft_strncmp(f_data + j, "SO", 2) && ft_isspace(f_data[j + 2]))
				cud->map->dirs->so_dir = ft_strdup(f_data + j + 3);
			if (!ft_strncmp(f_data + j, "WE", 2) && ft_isspace(f_data[j + 2]))
				cud->map->dirs->we_dir = ft_strdup(f_data + j + 3);
			if (!ft_strncmp(f_data + j, "EA", 2) && ft_isspace(f_data[j + 2]))
				cud->map->dirs->ea_dir = ft_strdup(f_data + j + 3);
		}
		return (clean_up_dir(cud->map->dirs));
	}
}