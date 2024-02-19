/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:06:17 by potero-d          #+#    #+#             */
/*   Updated: 2021/09/28 15:20:10 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux1;
	t_list	*aux2;

	aux1 = *lst;
	while (aux1)
	{
		aux2 = aux1->next;
		del(aux1->content);
		free(aux1);
		aux1 = aux2 ;
	}
	*lst = NULL;
}
