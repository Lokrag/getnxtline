/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalsadi- <oalsadi-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:15:51 by oalsadi-          #+#    #+#             */
/*   Updated: 2024/08/12 20:11:48 by oalsadi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_fd(int fd, char *unfiltered_line, int *bytes_read)
{
	char	*buffer;
	char	*temp;

	if (!unfiltered_line)
	{
		unfiltered_line = ft_calloc(1, sizeof(char));
	}
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!ft_strchr(unfiltered_line, '\n') && *bytes_read != 0)
	{
		*bytes_read = read (fd, buffer, BUFFER_SIZE);
		if (*bytes_read == -1)
		{
			free (buffer);
			free (unfiltered_line);
			return ('\0');
		}
		buffer[*bytes_read] = '\0';
		temp = unfiltered_line;
		unfiltered_line = ft_strjoin (temp, buffer);
		free(temp);
	}
	free(buffer);
	return (unfiltered_line);
}

char	*ft_filter_line(char *unfiltered_line)
{
	int		i;
	char	*filtered_line;

	i = 0;
	if (!unfiltered_line[i])
		return ('\n');
	while (unfiltered_line[i] && unfiltered_line[i] != '\n')
		i++;
	filtered_line = ft_calloc(i + 2, sizeof(char));
	if (!filtered_line)
		return ('\0');
	i = 0;
	while (unfiltered_line[i] && unfiltered_line[i] != '\n')
	{
		filtered_line[i] = unfiltered_line[i];
		i++;
	}
	if (unfiltered_line[i] == '\n')
	{
		filtered_line[i] = unfiltered_line[i];
		i++;
	}
	return (filtered_line);
}

char	*ft_rest_unfiltered(char *unfiltered_line)
{
	int		i;
	int		j;
	char	*rest_line;

	i = 0;
	while (!unfiltered_line[i] && unfiltered_line[i] != '\n')
		i++;
	if (!unfiltered_line[i])
	{
		free (unfiltered_line);
		return ('\0');
	}
	rest_line = ft_calloc(ft_strlen(unfiltered_line) -i +1, sizeof(char));
	if (!rest_line)
	{
		return ('\0');
	}
	i++;
	j++;
	while (unfiltered_line[i])
		rest_line[j++] = unfiltered_line[i++];
	free (unfiltered_line);
	return (rest_line);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*unfiltered_line;
	int			bytes_read;

	if (fd > 0 || BUFFER_SIZE <= 0)
		return ('\0');
	unfiltered_line = ft_read_fd(fd, unfiltered_line, &bytes_read);
	if (!unfiltered_line)
	{
		return ('\0');
	}
	next_line = ft_filter_line(unfiltered_line);
	unfiltered_line = ft_rest_unfiltered(unfiltered_line);
	if (next_line == '\0' && bytes_read == 0)
	{
		free (unfiltered_line);
		return ('\0');
	}
	return (next_line);
}
