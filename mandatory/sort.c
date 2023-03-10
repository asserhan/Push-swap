/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:18:06 by hasserao          #+#    #+#             */
/*   Updated: 2023/03/04 16:44:15 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	init_stack(stack);
	if((*stack)->index == (*stack)->max)
		ft_rotate_a(stack);
	else if ((*stack)->next->index == (*stack)->max)
		ft_reverse_rotate_a(stack);
	if((*stack)->index > (*stack)->next->index)
		ft_swap_a(stack);
}
void sort_under(t_list **stack)
{
	if (ft_lstsize(*stack) == 2)
		ft_swap_a(stack);
	else if (ft_lstsize(*stack) == 3)
		sort_three(stack);
}
int is_sorted(t_list **stack)
{
	t_list *tmp;
	tmp = *stack;
	while (tmp->next)
	{
		if(tmp->index > tmp->next->index)
			return(0);
		tmp = tmp->next;
	}
	return(1);
}

void sort_five(t_list **a,t_list **b)
{
	int i;
	int size;

	i = 0;
	if ((*a)->size == 4)
	{
		move_min_to_top(a);
		ft_push_b(a,b);
	}
	if ((*a)->size == 5)
	{
		move_min_to_top(a);
		ft_push_b(a,b);
		move_min_to_top(a);
		ft_push_b(a,b);
	}
	sort_three(a);
	size = ft_lstsize(*b);
	while (i < size)
	{
		ft_push_a(b,a);
		i++;
	}
}

