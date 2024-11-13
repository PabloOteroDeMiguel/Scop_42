/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:47:50 by potero-d          #+#    #+#             */
/*   Updated: 2021/10/26 15:48:25 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

void	ft_strlcpy2(char *dst, const char *src, size_t dstsize, size_t l)
{
	size_t			i;

	i = 0;
	if (dstsize > 0)
	{	
		while ((i < dstsize - 1) && (i < l))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*str;
// 	size_t	l;

// 	l = ft_strlen(s);
// 	if (!s)
// 		return (0);
// 	if (len > l)
// 		len = l;
// 	str = malloc(sizeof(char) * (len + 1));
// 	if (!str)
// 		return (0);
// 	if (start < l)
// 		ft_strlcpy2(str, &s[start], len + 1, l);
// 	else
// 		ft_strlcpy2(str, "", 1, l);
// 	return (str);
// }
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	l;
	size_t	max_len;

	if (!s)
		return (0);
	l = ft_strlen(s);
	if (start >= l)
		return (strdup(""));
	max_len = l - start;
	if (len > max_len)
		len = max_len;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy2(str, s + start, len + 1, len);
	return (str);
}

void	*ft_calloc_bzero(size_t count, size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	s = malloc(count * size);
	if (!s)
		return (0);
	while (i < (count * size))
	{
		s[i] = '\0';
		i++;
	}
	//s[i] = 0;
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{	
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
