/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:46:53 by hasserao          #+#    #+#             */
/*   Updated: 2023/03/15 17:28:15 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tt(void)
{
	system("leaks push_swap");
}

void	ft_error_msg(char *str)
{
	while (*str)
	{
		write(2, &*str, 1);
		str++;
	}
	write(2, "\n", 1);
	exit(1);
}
void ft_print_list(t_list *stack)
{
	t_list *tmp;
	tmp = stack;
	while (tmp != NULL)
	{
		ft_printf("%d\n",tmp->content);
		tmp=tmp->next;
	}
}
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	//atexit(tt);
	if (argc >= 2)
	{
		stack_a = NULL;
		stack_b = NULL;
		ft_get_list(argc, argv, &stack_a);
		if (is_sorted(&stack_a))
			return (ft_lstclear(&stack_a), 0);
		init_stack(&stack_a);
		if ((stack_a)->size <= 3)
			sort_under(&stack_a);
		else if ((stack_a)->size <= 5)
			sort_five(&stack_a, &stack_b);
		else if ((stack_a)->size < 200)
			chunk_sort(&stack_a, &stack_b, 5);
		else 
			chunk_sort(&stack_a, &stack_b, 9);
		//ft_print_list(stack_a);
		ft_lstclear(&stack_a);
	}
	else
		exit(0);
}
