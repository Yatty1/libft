/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:34:07 by syamada           #+#    #+#             */
/*   Updated: 2018/07/23 17:36:20 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		set_line(const int fd, char **line, char **text)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (text[fd][i] != '\n' && text[fd][i])
		i++;
	if (!(*line = ft_strsub(text[fd], 0, i)))
		return (-1);
	if (text[fd][i] == '\0')
	{
		ft_strdel(&text[fd]);
		return (1);
	}
	if (!(tmp = ft_strdup(text[fd] + i + 1)))
		return (-1);
	free(text[fd]);
	text[fd] = tmp;
	if (!text[fd][0])
		ft_strdel(&text[fd]);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[FDN];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			len;

	len = 0;
	while ((len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[len] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(str[fd], buf);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (len < 0 || fd < 0 || line == NULL)
		return (-1);
	if (len == 0 && !str[fd])
		return (0);
	return (set_line(fd, line, str));
}
