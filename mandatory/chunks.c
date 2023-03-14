/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:37:48 by hasserao          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:53 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunk(t_list **a, t_list **b, int chunk, int begin)
{
	static int	tmp_chunk;

	if ((*a)->size < 200)
		tmp_chunk = (*a)->size / 5;
	else
		tmp_chunk = (*a)->size / 9;
	while ((*a) && begin < chunk)
	{
		if (((*a)->index) < chunk)
		{
			if (((*a)->index) > ft_lstsize(*b) - (tmp_chunk / 2))
			{
				ft_push_b(a, b);
				ft_rotate_b(b);
			}
			else
				ft_push_b(a, b);
			begin++;
		}
		else
			ft_rotate_a(a);
	}
}

int	nbr_inst(t_list **stack, int pos)
{
	int	count;

	ft_init_pos(stack);
	if (pos < ft_lstsize(*stack) / 2)
		count = pos;
	else
		count = ft_lstsize(*stack) - pos;
	return (count);
}

void	push_back(t_list **a, t_list **b)
{
	int	max_pos;
	int	size;

	size = ft_lstsize(*b) - 1;
	while (*b)
	{
		if (*b && !((*b)->next))
		{
			ft_push_a(b, a);
			break ;
		}
		init_stack(b);
		max_pos = ft_get_pos(b, (*b)->max);
		if ((*b)->index == (*b)->max)
		{
			ft_push_a(b, a);
			size--;
		}
		else if (max_pos > size / 2)
			ft_reverse_rotate_b(b);
		else
			ft_rotate_b(b);
	}
}

void	chunk_sort(t_list **a, t_list **b, int d)
{
	int	chunk;
	int	i;
	int	j;

	i = 0;
	j = 1;
	chunk = (*a)->size / d;
	while (*a)
	{
		push_chunk(a, b, chunk * j, chunk * i);
		j++;
		i++;
	}
	push_back(a, b);
}
