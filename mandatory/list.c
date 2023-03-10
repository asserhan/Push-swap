/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:39:35 by hasserao          #+#    #+#             */
/*   Updated: 2023/03/04 12:09:18 by hasserao         ###   ########.fr       */
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
	t_list *tmp;
	tmp = *stack;
	new->index = 0;
	while (tmp)
	{
		if (new->content > tmp->content)
			new->index++;
		else
			tmp->index++;
		tmp = tmp->next;
	}
}
void ft_print_list(t_list *stack)
{
	t_list *tmp;
	tmp = stack;
	while (tmp)
	{
		ft_printf("%d\n",tmp->content);
		tmp = tmp->next;
	}
}
void ft_print_index(t_list **stack)
{
	while (*stack)
	{
		ft_printf("%d\n",(*stack)->index);
		(*stack) = (*stack)->next;
	}
}
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
	{
		lst = lst -> next;
	}
	return (lst);
}

