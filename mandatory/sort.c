/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:18:06 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/27 04:55:58 by hasserao         ###   ########.fr       */
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
void sort_four(t_list **stack_a,t_list **stack_b)
{

		if ((*stack_a)->min == (*stack_a)->top)
			ft_push_b(stack_a,stack_b);
		else
		{
			while ((*stack_a)->min != (*stack_a)->top)
			{
				if((*stack_a)->min_pos < (*stack_a)->md_pos)
					ft_rotate_a(stack_a);
				else
					ft_reverse_rotate_a(stack_a);
			}
			ft_push_b(stack_a,stack_b);
		}
		sort_three(stack_a);
		ft_push_a(stack_b,stack_a);
}
