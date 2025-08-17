/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:10:43 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/15 15:19:10 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp1;
	const unsigned char	*tmp2;
	size_t				idx;

	if (!dst && !src)
		return (NULL);
	idx = -1;
	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	while (++idx < n)
		tmp1[idx] = tmp2[idx];
	return (dst);
}
