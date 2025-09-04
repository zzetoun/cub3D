/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:59:38 by zzetoun           #+#    #+#             */
/*   Updated: 2025/09/04 20:59:38 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s1, const char *s2)
{
	const char	*temp_s2;

	if (!s1 || !s2)
		return (NULL);
	while (*s1)
	{
		temp_s2 = s2;
		while (*temp_s2)
		{
			if (*s1 == *temp_s2)
				return ((char *)s1);
			temp_s2++;
		}
		s1++;
	}
	return (NULL);
}
