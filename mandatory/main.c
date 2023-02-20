/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:46:53 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/20 18:32:05 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc,char **argv)
{
	if (argc >= 2)
	{
		t_list *stack_a = NULL;
		char **s;
		s = ft_parsing(argc,argv);
		check_input(&stack_a,s);

		while (stack_a)
		{
			ft_printf("%d\n",stack_a->content);
			stack_a = stack_a->next;
		}
		system("leaks push_swap");
	}
	else
		exit(EXIT_FAILURE);

}
