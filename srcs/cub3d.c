/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:56:01 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/25 00:22:51 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/cub3d.h"

static void	print_colors(t_cud *cud)
{
    int i, j;

    for (i = 0; i < 2; i++)
    {
        printf("%s colors: ", i == F ? "Floor" : "Ceiling");
        if (cud->par.cs[i].colors)
        {
            for (j = 0; j < 3; j++)
                printf("%d ", cud->map.fc_colors[i][j]);
        }
        printf("\n");
    }
}

static void	print_dirs(t_cud *cud)
{
    int i;

    const char *names[4] = {"NO", "EA", "SO", "WE"};
    for (i = 0; i < 4; i++)
        printf("%s dir: %s\n", names[i], cud->par.dirs[i] ? cud->par.dirs[i] : "NULL");
}

static void	print_xpms(t_cud *cud)
{
    int i;
    const char *names[4] = {"NO", "EA", "SO", "WE"};

    for (i = 0; i < 4; i++)
        printf("%s XPM: %p (width=%d, height=%d)\n",
               names[i],
               cud->map.xpms[i].xpm_file,
               cud->map.xpms[i].img_width,
               cud->map.xpms[i].img_height);
}

static void	print_file_data(t_cud *cud)
{
    int i = 0;
    if (!cud->par.data)
        return;
    while (cud->par.data[i])
    {
        printf("Line %d: %s\n", i, cud->par.data[i]);
        i++;
    }
}

void	test_print_cud(t_cud *cud)
{
    printf("---- PRINTING CUD STRUCT ----\n");
    print_dirs(cud);
    print_file_data(cud);
    print_colors(cud);
    print_xpms(cud);
    printf("-----------------------------\n");
}

int	main(int ac, char **av)
{
	t_cud	cud;
	
	if (ac != 2)
		return (errmsg(ARGERR, NULL));
	ft_memset(&cud, '\0', sizeof(cud));
	cud.mlx = mlx_init();
	if (!cud.mlx)
		return (errmsg(MLXINIERR, NULL));
	if (file_parsing(av[1], &cud))
	{
		freedom(&cud);
		return(EXIT_FAILURE);
	}
	// here to add excution
	test_print_cud(&cud);
	freedom(&cud);
	return (EXIT_SUCCESS);
}
