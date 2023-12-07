/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenet <mabenet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:11:22 by mabenet           #+#    #+#             */
/*   Updated: 2023/11/13 16:09:59 by mabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] || str[i] == '\n')
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;
	char	*s;
	size_t	i;
	size_t	n;

	if (size != 0 && nmemb * size / size != nmemb)
		return (NULL);
	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	i = 0;
	s = (char *)str;
	n = ft_strlen(s);
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
char	*ft_readline(int fd)
{
	void	*buffer;
	char	*res;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer || BUFFER_SIZE < 0)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	res = (char *)buffer;
	//free (buffer);
	return (res);
}

char	*ft_line(char *s)
{
	char *str;
	int	i;

	i = 0;
	str = ft_calloc(ft_strlen(s) + 1 , sizeof(char));
	if(!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		if (s[i] == '\n')
			return (str);
		i++;
		
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char	*line;
	char	*add;
	char	*buffer;

	buffer = NULL;
	if (fd < 0 )
		return (NULL);
	add = NULL;
	if (res == 0)
		res = ft_readline(fd);
	while (ft_check(res) == 0)
	{
		add = ft_readline(fd);
		res = ft_wline(res, add);
	}
	line = ft_line(res);
	res = ft_clean(res);
	if (read (fd, buffer, BUFFER_SIZE) == 0)
		return (NULL);
	return (line);
	//free(line);
}
