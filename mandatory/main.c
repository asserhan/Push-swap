/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:46:53 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/22 17:50:20 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void tt(void)
{
	system("leaks push_swap");
}
void ft_print_list(t_list *stack)
{
	while (stack)
	{
		ft_printf("%d\n",stack->content);
		stack = stack->next;
	}
}
int main(int argc,char **argv)
{
		atexit(tt);
	if (argc >= 2)
	{
		t_list *stack_a = NULL;
		//t_list *stack_b = NULL;
		ft_get_list(argc,argv,&stack_a);
		ft_print_list(stack_a);
		ft_printf("index\n");
		index_list(&stack_a);
		// ft_print_index(&stack_a);
		ft_lstclear(&stack_a);
	}
	else
		exit(EXIT_FAILURE);

}
