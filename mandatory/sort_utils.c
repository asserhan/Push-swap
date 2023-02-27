/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:26:49 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/27 02:54:33 by hasserao         ###   ########.fr       */
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
void lst_min(t_list **stack)
{
	if (!(*stack) || !stack)
		return;
	t_list *curr;

	curr = (*stack);
	(*stack)->min = (*stack)->index;
	while (curr)
	{
		if ((*stack)->min > curr->index)
			(*stack)->min = curr->index;
		curr = curr->next;
	}
}
void lst_max(t_list **stack)
{
	if (!(*stack) || !stack)
		return;
	t_list *curr;

	curr = (*stack);
	(*stack)->max = (*stack)->index;
	while (curr)
	{
		if ((*stack)->max < curr->index)
			(*stack)->max = curr->index;
		curr = curr->next;
	}
}
void init_stack(t_list **stack)
{

	(*stack)->top = (*stack)->index;
	(*stack)->bott = ft_lstlast(*stack)->index;
	(*stack)->md = ft_lstmiddle(*stack)->index;
	lst_min(stack);
	lst_max(stack);
	(*stack)->min_pos = find_position(stack,(*stack)->min);
	(*stack)->max_pos = find_position(stack,(*stack)->max);
	(*stack)->md_pos =find_position(stack,(*stack)->md);
}
