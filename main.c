/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalsadi- <oalsadi-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:19:03 by oalsadi-          #+#    #+#             */
/*   Updated: 2024/08/13 13:00:00 by oalsadi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*linea;
	int		i;
	int		fd1;

	i = 0;
	fd1 = open("LaBibliotecaDeBabel.txt", O_RDONLY);

	while (i < 5)
	{
		linea = get_next_line(fd1);
		printf("line [%02d] : %s", i, linea);
		free(linea);
		i++;
	}
	close (fd1);
	return (0);
}
