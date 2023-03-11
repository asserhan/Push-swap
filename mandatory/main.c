/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:46:53 by hasserao          #+#    #+#             */
/*   Updated: 2023/03/10 23:43:37 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void tt(void)
{
	system("leaks push_swap");
}

int main(int argc,char **argv)
{
		//atexit(tt);
	if (argc >= 3)
	{
		t_list *stack_a = NULL;
		t_list *stack_b = NULL;
		ft_get_list(argc,argv,&stack_a);
		if(is_sorted(&stack_a))
			return(ft_lstclear(&stack_a),0);
		init_stack(&stack_a);
		if ((stack_a)->size == 2 || (stack_a)->size == 3)
			sort_under(&stack_a);
		if ((stack_a)->size == 4 || (stack_a)->size == 5 )
			sort_five(&stack_a,&stack_b);
		// ft_print_index(&stack_a);
		else
			chunk_sort(&stack_a,&stack_b);
		// ft_printf("*******\n");
		// ft_print_list(stack_b);
		// ft_printf("*******\n");
		// ft_print_list(stack_a);
		// ft_lstclear(&stack_a);
	}
	else
		exit(0);

}
