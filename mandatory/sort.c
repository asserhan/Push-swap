/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:18:06 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/28 20:46:59 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	if (((*stack)->top) > ((*stack)->md) && ((*stack)->bott) > ((*stack)->md)
		&& (((*stack)->bott) > ((*stack)->top)))
		ft_swap_a(stack);
	else if (((*stack)->top) > ((*stack)->md)
		&& ((*stack)->md) > ((*stack)->bott)
		&& ((*stack)->top) > ((*stack)->bott))
	{
		ft_swap_a(stack);
		ft_reverse_rotate_a(stack);
	}
	else if (((*stack)->top) > ((*stack)->md)
		&& ((*stack)->md) < ((*stack)->bott)
		&& ((*stack)->top) > ((*stack)->bott))
		ft_rotate_a(stack);
	else if (((*stack)->top) < ((*stack)->md)
		&& ((*stack)->top) < ((*stack)->bott)
		&& ((*stack)->md) > ((*stack)->bott))
	{
		ft_swap_a(stack);
		ft_rotate_a(stack);
	}
	else if (((*stack)->top) < ((*stack)->md)
		&& ((*stack)->top) > ((*stack)->bott)
		&& ((*stack)->md) > ((*stack)->bott))
		ft_reverse_rotate_a(stack);
}

int find_position(t_list **stack,int to_find)
{
	t_list *curr;
	curr = (*stack);
	int position;
	position = 0;
	while (curr)
	{
		if(curr->index == to_find)
			return (position);
		position++;
		curr = curr->next;
	}
	return(-1);
}
int is_sorted(t_list **stack)
{
	while ((*stack)->next)
	{
		if((*stack)->index > (*stack)->next->index)
			return(0);
		(*stack) = (*stack)->next;
	}
	return(1);
}
void init_pos(t_list **stack)
{
	t_list *curr;
	curr = (*stack);
	int i;
	i = 0;
	while (curr)
	{
		curr->pos = i;
		i++;
		curr = curr->next;
	}
}
void sort_five(t_list **stack_a,t_list **stack_b)
{
	if (ft_lstsize(&stack_a) == 4)
	{
		
	}
}
