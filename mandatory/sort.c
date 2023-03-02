/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:18:06 by hasserao          #+#    #+#             */
/*   Updated: 2023/03/02 01:31:16 by hasserao         ###   ########.fr       */
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
	
}
