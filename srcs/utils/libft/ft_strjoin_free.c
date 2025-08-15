/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:10:01 by zzetoun           #+#    #+#             */
/*   Updated: 2025/05/07 18:10:01 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*str;
	int		idx;
	int		jdx;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	idx = -1;
	while (s1[++idx])
		str[idx] = s1[idx];
	jdx = 0;
	while (s2 && s2[jdx])
		str[idx++] = s2[jdx++];
	str[idx] = '\0';
	free(s1);
	return (str);
}
