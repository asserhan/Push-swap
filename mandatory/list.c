/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:39:35 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/22 18:00:11 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_get_list(int argc,char **argv,t_list **stack_a)
{
	int i;
	char **list;
	t_list *new;
	i = 0;
	list = ft_parsing(argc,argv);
	while (list[i])
	{
		new = ft_lstnew(ft_atoi(list[i]));
		index_list(stack_a,new);
		ft_lstadd_back(stack_a, new);
		i++;
	}
	free_strings(list);
}

void index_list(t_list **stack,t_list *new)
{
	(*stack)->pos = 0;
	while (*stack)
	{
		if (new->content < (*stack)->content)
			(*stack)->pos++;
		else
			new->pos++;
		(*stack) = (*stack)->next;
	}
}
void ft_print_index(t_list **stack)
{
	while (*stack)
	{
		ft_printf("%d\n",(*stack)->pos);
		(*stack) = (*stack)->next;
	}
}
