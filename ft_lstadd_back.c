/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 03:36:14 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/27 04:04:46 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*cur;

	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	if (!lst || !new_node)
		return ;
	cur = *lst;
	while (cur && cur->next != NULL)
		cur = cur->next;
	cur->next = new_node;
}
