/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:46:53 by hasserao          #+#    #+#             */
/*   Updated: 2023/03/13 23:32:28 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tt(void)
{
	system("leaks push_swap");
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
		if ((stack_a)->size == 2 || (stack_a)->size == 3)
			sort_under(&stack_a);
		else if ((stack_a)->size == 4 || (stack_a)->size == 5)
			sort_five(&stack_a, &stack_b);
		// ft_print_index(&stack_a);
		else if ((stack_a)->size < 200)
			chunk_sort(&stack_a, &stack_b, 5);
		else if ((stack_a)->size >= 200)
			chunk_sort(&stack_a, &stack_b, 9);
		//  ft_printf("*******\n");
		// ft_print_list(stack_b);
		// ft_printf("*******\n");
		ft_print_list(stack_a);
		// ft_lstclear(&stack_a);
	}
	else
		exit(0);
}
