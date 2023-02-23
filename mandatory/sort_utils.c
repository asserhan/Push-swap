/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:26:49 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/23 19:56:39 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
	{
		lst = lst -> next;
	}
	return (lst);
}
t_list *ft_lstmiddle(t_list *lst)
{
	if (!lst)
		return (NULL);
	t_list *node1 = lst;
	t_list *node2 = lst;
	while (node2 != NULL && node2->next != NULL)
		{
			node2 = node2->next->next;
			node1= node1->next;
		}
	return (node1);
}
void init_stack(t_list **stack)
{

	(*stack)->top = (*stack)->index;
	(*stack)->bott = ft_lstlast(*stack)->index;
	(*stack)->md = ft_lstmiddle(*stack)->index;

}
