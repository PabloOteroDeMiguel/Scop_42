/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:52:31 by potero            #+#    #+#             */
/*   Updated: 2024/02/19 18:52:53 by potero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	error_no(int e)
{
	if (e == 0)
	{
		printf("Error\nWrong file.\n");
        exit(0);
	}
    if (e ==  1)
    {
         printf("Error\nWrong number of arguments.\n");
         exit(1);
    }
    if (e ==  2)
    {
         printf("Error\nCould not allocate memory for vertices and faces.\n");
         exit(1);
    }
}