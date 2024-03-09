/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:24:02 by potero            #+#    #+#             */
/*   Updated: 2022/01/20 13:44:45 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include<unistd.h>
# include<fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE 10

size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_strlcpy2(char *dst, const char *src, size_t dstsize, size_t l);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc_bzero(size_t count, size_t size);
char	*get_next_line(int fd);
#endif
