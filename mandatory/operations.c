/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:02:10 by hasserao          #+#    #+#             */
/*   Updated: 2023/03/13 21:14:25 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap_a(t_list **stack)
{
	int tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	write (1,"sa\n",3);
}

void ft_rotate_a(t_list **stack)
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
	write (1,"ra\n",3);
}

void ft_reverse_rotate_a(t_list **stack)
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
	write (1,"rra\n",4);


}

void ft_push_a(t_list **b,t_list **a)
{
	t_list *tmp;
	if (*b == NULL)
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	write(1,"pa\n",3);
}

