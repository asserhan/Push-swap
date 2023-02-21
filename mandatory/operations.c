/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:02:10 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/20 21:28:56 by hasserao         ###   ########.fr       */
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
	while (curr->next)
		curr = curr->next;
	curr->next = head;
	head->next = NULL;
}
