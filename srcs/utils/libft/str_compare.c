/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:28:30 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/16 17:35:01 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_compare(char const *s1, char const *s2)
{
	int	result;

	if (!s1 || !s2)
		return (0);
	result = (!ft_strncmp(s1, s2, ft_strlen(s2)));
	result *= (ft_strlen(s1) == ft_strlen(s2));
	return (result);
}