/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:59:37 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/27 16:50:13 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMULAS_H
# define FORMULAS_H

# include <math.h>

typedef struct s_vector
{
    int a;
    int b;
}   t_vector;

typedef struct s_triangle
{
    float x;
    float y;
    float z;
}   t_triangle;

float ratios_of_sides(const t_triangle *viewplane, const t_triangle *object);

#endif
