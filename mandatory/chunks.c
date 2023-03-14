/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:37:48 by hasserao          #+#    #+#             */
/*   Updated: 2023/03/14 03:04:18 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_chunk(t_list **a,t_list **b,int chunk, int d)
{
	static int tmp_chunk ;
	tmp_chunk = (*a)->size / 5;
	while ( (*a) && d < chunk)
	{
		if (((*a)->index) < chunk)
		{
			if (((*a)->index) > ft_lstsize(*b) - (tmp_chunk / 2))
			{
				ft_push_b(a,b);
				ft_rotate_b(b);
			}
			else
				ft_push_b(a,b);
			d++;
		}
		else
			ft_rotate_a(a);
	}
}

int nbr_inst(t_list **stack,int pos)
{
	int count;
	ft_init_pos(stack);
	if (pos < ft_lstsize(*stack) / 2)
		count = pos;
	else
		count = ft_lstsize(*stack) - pos;
	return (count);
}

void move_to_top(t_list **stack,int position,int index)
{
	if (position < ft_lstsize(*stack) / 2)
	{
		while (position != 0)
		{
				ft_rotate_b(stack);
				position = ft_get_pos(stack,index);
		}
	}
	else
	{
		while (position != 0)
		{
				ft_reverse_rotate_b(stack);
				position = ft_get_pos(stack,index);
		}
	}
}
void push_back(t_list **a,t_list **b)
{
	int max_pos;
	//int b_max_pos;
	int i;
	int size;
	size = ft_lstsize(*b) - 1;
	i = 0;

	while (*b)
	{
		init_stack(b);
		max_pos = ft_get_pos(b,(*b)->max);
		if ((*b)->index == (*b)->max)
		{
			ft_push_a(b,a);
			size--;
		}
		else if (max_pos > size / 2)
			ft_reverse_rotate_b(b);
		else
			ft_rotate_b(b);

	}
	// while (*b)
	// {
	// 	init_stack(b);
	// 	if(*b && !((*b)->next))
	// 	{
	// 		ft_push_a(b,a);
	// 		break;
	// 	}
	// 	max_pos = ft_get_pos(b,(*b)->max);
	// 	b_max_pos = ft_get_pos(b,(*b)->b_max);

	// 	if(nbr_inst(b,max_pos) < nbr_inst(b,b_max_pos))
	// 	{
	// 		move_to_top(b,max_pos,(*b)->max);
	// 		ft_push_a(b,a);
	// 	}
	// 	else
	// 	{
	// 		move_to_top(b, b_max_pos,(*b)->b_max);
	// 		ft_push_a(b,a);
	// 		move_to_top(b, max_pos,(*b)->max);
	// 		ft_push_a(b,a);
	// 		ft_swap_a(a);
	// 		size--;
	// 	}
	// 	size--;
	// }
}



void chunk_sort(t_list **a,t_list **b,int d)
{
	int chunk;
	int i ;
	int j;


	i = 0;
	j = 1;
	chunk = (*a)->size / d;
	while (*a)
	{
		push_chunk(a,b,chunk * j , chunk * i);
		j++;
		i++;
	}
	// ft_printf("********\n");
	// ft_print_list(*b);
	push_back(a,b);
}
