/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalsadi- <oalsadi-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:17:26 by oalsadi-          #+#    #+#             */
/*   Updated: 2024/08/13 12:17:31 by oalsadi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (s[i]);
	if (s[i] == '\0')
		return (&s[i]);
	return ('\0');
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	a;

	i = 0;
	a = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == a)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0')
		return ((char *)&s[i]);
	return ('\0');
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	unsigned char	s1len;
	unsigned char	s2len;
	unsigned char	newlen;
	int				i;

	if (!s1 && !s2)
		return ('\0');
	s1len = ft_strlen (s1);
	s2len = ft_strlen (s2);
	newlen = s1len + s2len;
	new = (char *)malloc(sizeof(char) + (newlen + 1));
	if (new == '\0')
		return ('\0');
	i = -1;
	while (s1[i++])
		new[i] = s1[i];
	i = -1;
	while (s2[i++])
		new [i + s1len] = s2 [i];
	new[newlen] = '\0';
	return (new);
}

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *) str;
	while (n > 0)
	{
		*p = (unsigned char)c;
		p++;
		n--;
	}
	return (str);
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;
	size_t	total_size;

	if (nelem == '\0' || elsize == '\0')
	{
		return (malloc(0));
	}
	total_size = nelem * elsize;
	if ((total_size > 2147483647) || (total_size / elsize != nelem))
	{
		return ('\0');
	}
	ptr = malloc (total_size);
	if (ptr == '\0')
	{
		return ('\0');
	}
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
