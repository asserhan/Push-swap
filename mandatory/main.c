/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:46:53 by hasserao          #+#    #+#             */
/*   Updated: 2023/03/02 01:30:09 by hasserao         ###   ########.fr       */
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
		//t_list *stack_b = NULL;
		ft_get_list(argc,argv,&stack_a);
		if(is_sorted(&stack_a))
			return(ft_lstclear(&stack_a),0);
		init_stack(&stack_a);
		ft_print_list(stack_a);
		// if ((stack_a)->size >= 2)
		// 	sort_under(&stack_a);
		if ((stack_a)->size >= 4)
			sort_five(&stack_a);
		ft_print_list(stack_a);
		ft_lstclear(&stack_a);
	}
	else
		exit(EXIT_FAILURE);

}
