/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:37:48 by hasserao          #+#    #+#             */
/*   Updated: 2023/03/10 23:42:10 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_chunk(t_list **a,t_list **b,int chunk, int d)
{
	// ft_print_index(a);
	// t_list *tmp = *a;
	while ( (*a) && d < chunk)
	{
		// ft_printf("%d ***** %d\n", (*a)->index, chunk);
		if (((*a)->index) < chunk)
		{
			ft_push_b(a,b);
			d++;
		}
		else
		{
			// ft_printf("chunk %d\n", (*a)->index);
			// ft_printf("else\n");
			ft_rotate_a(a);
		}
		//  (*a)=(*a)->next;
	}

}
void chunk_sort(t_list **a,t_list **b)
{
	int chunk;
	int i = 0;
	int j = 1;
	chunk = (*a)->size / 5;
	// ft_printf("%d", chunk);
	// (void )b;
	while (*a)
	{
		// ft_printf("%d///////////////\n", chunk * i);
		push_chunk(a,b,chunk * j , chunk * i);
		j++;
		i++;
	}

}
