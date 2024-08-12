/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalsadi- <oalsadi-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:15:51 by oalsadi-          #+#    #+#             */
/*   Updated: 2024/08/12 20:13:03 by oalsadi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1042

# endif

char	*ft_read_fd(int fd, char *unfiltered_line, int *bytes_read);
char	*ft_filter_line(char *unfiltered_line);
char	*ft_rest_unfiltered(char *unfiltered_line);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_calloc(size_t nelem, size_t elsize);
#endif