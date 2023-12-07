/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenet <mabenet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:11:10 by mabenet           #+#    #+#             */
/*   Updated: 2023/12/07 10:19:37 by mabenet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int	i;

	fd = open("test.txt", O_RDONLY);
	while (get_next_line(fd) != NULL)
	{
		get_next_line(fd);
		i++;
		printf("%d", i);
	}
	close(fd);
}
