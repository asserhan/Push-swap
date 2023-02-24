/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:18:06 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/24 15:58:15 by hasserao         ###   ########.fr       */
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
