/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:02:10 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/21 20:08:30 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_list **stack)
{
	int tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->pos;
	(*stack)->pos = (*stack)->next->pos;
	(*stack)->next->pos = tmp;
}

void ft_rotate(t_list **stack)
{
	t_list *curr;
	t_list *head;

	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	curr = *stack;
	*stack = (*stack)->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = head;
	head->next = NULL;
}
void ft_reverse_rotate(t_list **stack)
{
	t_list *curr;
	t_list *last;

	if (!*stack || !(*stack)->next)
		return ;
	curr = *stack;
	while (curr->next->next != NULL)
		curr = curr->next;
	last = curr->next;
	last->next = *stack;
	*stack = last;
	curr->next = NULL;

}
