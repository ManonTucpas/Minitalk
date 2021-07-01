/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:05:41 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/07/01 13:03:15 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_strdup(""));
	while (s[i])
	{
		if (s[i] == '\n')
			return (ft_substr(s, 0, i));
		i++;
	}
	return (ft_strdup(s));
}

static char	*ft_new_stock(char *s)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[j])
		j++;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i] || !s[i + 1])
	{
		free(s);
		s = NULL;
		return (NULL);
	}
	i++;
	tmp = ft_substr(s, i, j - i);
	free(s);
	s = NULL;
	return (tmp);
}

static void	ft_getstock(char **stock, char *buffer)
{
	char	*tmp;

	if (*stock == NULL)
		tmp = ft_strdup(buffer);
	else
		tmp = ft_strjoin(*stock, buffer);
	if (*stock)
		free(*stock);
	*stock = tmp;
}

int	get_next_line(int fd, char **line)
{
	int			len_read;
	static char	buffer[BUFFER_SIZE + 1];
	static char	*stock[256];

	len_read = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (ft_strchr(stock[fd], '\n') == 0
		&& (read(fd, buffer, BUFFER_SIZE) > 0))
	{
		len_read = read(fd, buffer, BUFFER_SIZE);
		buffer[len_read] = '\0';
		ft_getstock(&stock[fd], buffer);
	}
	if (len_read == -1)
		return (-1);
	*line = ft_line(stock[fd]);
	if (*line == NULL)
		*line = ft_strdup("");
	stock[fd] = ft_new_stock(stock[fd]);
	if (len_read == 0)
		return (0);
	return (1);
}
