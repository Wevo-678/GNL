/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenet <mabenet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:53:09 by mabenet           #+#    #+#             */
/*   Updated: 2023/11/02 10:03:05 by mabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_check(char *s)
{
    int i;

    i = 0;

    if (s[i] == '\n')
        return (1);
    else if (ft_strlen(s) == 1 && s[i] != '\n')
        return (0);
    else
    {
    while (s[i])
        {
          if (s[i] == '\n')
                return (i);
            i++;
        }
    }
    return (0);
}

void    ft_putstr(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    
}
char	*ft_wline(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!res)
		return (0);
	while (s1[j])
	{
		res[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char *ft_clean(char *s)
{
    int     i;
    int     j;
    char    *str;

    i = 0;
    j = 0;
    while (s[i] != '\n')
        i++;
    str = ft_calloc(i + 1, sizeof(char)); // strlen -i

    while (s[i + 1])
    {
        str[j] = s[i + 1];
        i++;
        j++;

    }
    free (s);
    return (str);
}
