/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:37:48 by hasserao          #+#    #+#             */
/*   Updated: 2023/03/15 18:41:54 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk(t_list **a, t_list **b, int tmp_chunk,int chunk)
{
	int i;

	i = 0;
	while ((*a) && i < chunk)
	{
		if (((*a)->index) <= tmp_chunk)
		{
			if ((*a)->index > tmp_chunk - (chunk / 2))
			{
				ft_push_b(a,b);
				ft_rotate_b(b);
			}
			else
				ft_push_b(a,b);
			i++;
		}
		else
			ft_rotate_a(a);
	}

}

int	nbr_inst(t_list **stack, int pos)
{

	if (pos < ft_lstsize(*stack) / 2)
		return(pos);
	else
		return (ft_lstsize(*stack) - pos);

}
int is_top_half(t_list **stack,int index)
{
	int i;
	int middle;
	t_list *tmp;

	i = 0;
	middle = ft_lstsize(*stack)/2;
	tmp = *stack;
	while (tmp && tmp->index != index)
	{
		tmp = tmp->next;
		i++;
	}
	if (i<middle)
		return (1);
	else
		return (0);
}
void move_to_top(t_list **stack,int index)
{
	if (is_top_half(stack,index))
		while ((*stack) && (*stack)->index != index)
			ft_rotate_b(stack);
	else
		while ((*stack) && (*stack)->index != index)
			ft_reverse_rotate_b(stack);
}

void	push_to_a(t_list **a, t_list **b)
{
	// int	max;
	// int b_max;
	int	size;

	size = ft_lstsize(*b) - 1;
	while (size >= 0)
	{
		if(*b && !(*b)->next)
			ft_push_a(b,a);
		// max = ft_get_pos(*b,size);
		// b_max = ft_get_pos(*b,size - 1);
		// if (nbr_inst(b,max)  < nbr_inst(b,b_max))
		// {
			move_to_top(b,size);
			ft_push_a(b,a);
		// }
		// else
		// {
		// 	move_to_top(b,size - 1);
		// 	ft_push_a(b,a);
		// 	move_to_top(b,size);
		// 	ft_push_a(b,a);
		// 	ft_swap_a(a);
		// 	size--;
		// }
		size--;
	}
}


void	chunk_sort(t_list **a, t_list **b, int d)
{
	int	chunk;
	int tmp_chunk;

	chunk = ft_lstsize(*a) / d;
	tmp_chunk = chunk;
	while (*a)
	{
		push_chunk(a,b,tmp_chunk,chunk);
		tmp_chunk = tmp_chunk + chunk;
	}
	push_to_a(a, b);
}
