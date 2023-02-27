/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:46:53 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/27 03:57:56 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void tt(void)
{
	system("leaks push_swap");
}

int main(int argc,char **argv)
{
		atexit(tt);
	if (argc >= 2)
	{

		t_list *stack_a = NULL;
		t_list *stack_b = NULL;
		ft_get_list(argc,argv,&stack_a);
		init_stack(&stack_a);
		ft_print_list(stack_a);
		if (argc == 4)
			sort_three(&stack_a);
		if (argc == 5)
			sort_four(&stack_a,&stack_b);
		ft_print_list(stack_a);
		ft_lstclear(&stack_a);



	}
	else
		exit(EXIT_FAILURE);

}
