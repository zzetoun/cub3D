/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzetoun <zzetoun@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:38:49 by zzetoun           #+#    #+#             */
/*   Updated: 2025/08/16 14:13:27 by zzetoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_remain(char *buff)
{
	char	*remain;
	int		idx;
	int		jdx;

	idx = 0;
	while (buff[idx] && buff[idx] != '\n')
		idx++;
	if (!buff[idx])
		return (free(buff), buff = NULL, NULL);
	remain = ft_calloc(ft_strlen(buff) + 1 - idx++, sizeof(char));
	if (!remain)
		return (free(buff), buff = NULL, NULL);
	jdx = 0;
	while (buff[idx])
		remain[jdx++] = buff[idx++];
	remain[jdx] = '\0';
	free(buff);
	buff = NULL;
	return (remain);
}

char	*ft_line(char *buff)
{
	char	*line;
	int		len;

	if (!ft_strlen(buff))
		return (NULL);
	len = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	if (buff[len] == '\n')
		line = ft_calloc(len + 2, sizeof(char));
	else
		line = ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	if (buff[len] == '\n')
		line[len + 1] = '\0';
	else
		line[len] = '\0';
	while (len >= 0)
	{
		line[len] = buff[len];
		len--;
	}
	return (line);
}

char	*ft_read_file(char *buff, int fd)
{
	char	*line;
	int		len;

	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (free(buff), buff = NULL, NULL);
	len = 1;
	while (!ft_strchr(buff, '\n') && len != 0)
	{
		len = read(fd, line, BUFFER_SIZE);
		if (len < 0)
		{
			free(line);
			free(buff);
			buff = NULL;
			return (NULL);
		}
		line[len] = '\0';
		buff = ft_strjoin(buff, line);
	}
	free(line);
	return (buff);
}

char	*gnl(int fd, char **tmp)
{
	static char	*buff;
	char		*line;

	if (tmp && *tmp)
	{
		free((*tmp));
		*tmp = NULL;
	}
	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	buff = ft_read_file(buff, fd);
	if (!buff)
		return (NULL);
	line = ft_line(buff);
	if (!line)
		return (free(buff), buff = NULL, NULL);
	buff = ft_remain(buff);
	if (buff && *buff == '\0')
	{
		free(buff);
		buff = NULL;
	}
	return (line);
}
