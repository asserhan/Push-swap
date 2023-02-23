/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:02:10 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/23 21:25:20 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap_a(t_list **stack)
{
	int tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	write (1,"sa\n",3);
}

void ft_rotate_a(t_list **stack)
{
	t_list *curr;
	t_list *head;

	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	curr = *stack;
	*stack = (*stack)->next;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = head;
	head->next = NULL;
	write (1,"ra\n",3);
}
void ft_reverse_rotate(t_list **stack)
{
	t_list *curr;
	t_list *last;

	if (!*stack || !(*stack)->next)
		return ;
	curr = *stack;
	while (curr->next->next != NULL)
		curr = curr->next;
	last = curr->next;
	last->next = *stack;
	*stack = last;
	curr->next = NULL;

}

// void ft_push(t_list **from,t_list **to)
// {
// 	t_list *tmp;
// 	if (*from)
// 	{
// 		tmp = *from;
// 		*from = (*from)->next;
// 		tmp->next = *to;
// 		*to = tmp;
// 	}
// }
// void ft_choose_op(char *op,t_list **a,t_list **b)
// {
// 	if (ft_strcmp(op,"sa") == 0)
// 		ft_swap(a);
// 	else if (ft_strcmp(op,"sb") == 0)
// 		ft_swap(b);
// 	else if (ft_strcmp(op,"ss") == 0)
// 		{
// 			ft_swap(a);
// 			ft_swap(b);
// 		}
// 	else if (ft_strcmp(op,"pa") == 0)
// 		ft_push(b,a);
// 	else if (ft_strcmp(op,"pb") == 0)
// 		ft_push(a,b);
// 	else if (ft_strcmp(op,"ra") == 0)
// 		ft_rotate(a);
// 	else if (ft_strcmp(op,"rb") == 0)
// 		ft_rotate(b);
// 	else if (ft_strcmp(op,"rr") == 0)
// 		{
// 			ft_rotate(a);
// 			ft_rotate(b);
// 		}
// 	else if (ft_strcmp(op,"rra") == 0)
// 		ft_reverse_rotate(a);
// 	else if (ft_strcmp(op,"rrb") == 0)
// 		ft_reverse_rotate(b);
// 	else if (ft_strcmp(op,"rrr") == 0)
// 		{
// 			ft_reverse_rotate(a);
// 			ft_reverse_rotate(b);
// 		}
// }
