/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 09:00:00 by hasserao          #+#    #+#             */
/*   Updated: 2023/03/15 18:24:29 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_pos(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
}

int	ft_get_min_pos(t_list **stack)
{
	t_list	*tmp;
	int		min_pos;

	tmp = *stack;
	init_stack(stack);
	ft_init_pos(stack);
	min_pos = tmp->pos;
	while (tmp)
	{
		if ((*stack)->min == tmp->index)
			min_pos = tmp->pos;
		tmp = tmp->next;
	}
	return (min_pos);
}

int	ft_get_pos(t_list *stack, int index)
{
	int		position;

	position = 0;
	while (stack)
	{
		if(stack->index == index)
			return(position);
		position++;
		stack=stack->next;
	}
	return (-1);
}

void	move_min_to_top(t_list **stack)
{
	int	min_pos;

	min_pos = ft_get_min_pos(stack);
	if (min_pos < ((*stack)->size) / 2)
	{
		while (min_pos != 0)
		{
			ft_rotate_a(stack);
			min_pos = ft_get_min_pos(stack);
		}
	}
	else
	{
		while (min_pos != 0)
		{
			ft_reverse_rotate_a(stack);
			min_pos = ft_get_min_pos(stack);
		}
	}
}
