/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:01:30 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/24 18:55:29 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap_b(t_list **stack)
{
	int tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	write (1,"sb\n",3);
}

void ft_rotate_b(t_list **stack)
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
	write (1,"rb\n",3);
}
void ft_reverse_rotate_b(t_list **stack)
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
	write (1,"rrb\n",4);


}

void ft_push_b(t_list **a,t_list **b)
{
	t_list *tmp;
	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
	}
	write(1,"pb\n",3);
}
