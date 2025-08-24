/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 23:09:13 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/24 18:26:11 by zzetoun          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    size_t  start;
    size_t  end;
    char    *trimmed_str;

    if (!s1 || !set)
        return (NULL);
    start = 0;
    while (s1[start] && ft_strchr(set, s1[start]))
        start++;
    end = ft_strlen(s1);
    while (end > start && ft_strchr(set, s1[end - 1]))
        end--;
    trimmed_str = ft_substr(s1, start, end - start);
    return (trimmed_str);
}
