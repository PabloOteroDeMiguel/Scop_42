/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:52:31 by potero            #+#    #+#             */
/*   Updated: 2024/02/19 18:52:53 by potero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void    validateFile(char *file)
{
    printf("Validating file..\n");
    file_name(file);
    printf("Success\n");
}

void	file_name(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'j')
		i--;
	else
		error_no(0);
	if (str[i] == 'b')
		i--;
	else
		error_no(0);
	if (str[i] == 'o')
		i--;
	else
		error_no(0);
	if (str[i] == '.')
		i--;
	else
		error_no(0);
}