/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:46:53 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/21 20:09:41 by hasserao         ###   ########.fr       */
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
		char **s;
		s = ft_parsing(argc,argv);
		check_input(&stack_a,s);
		free_strings(s);
		t_list *tmp = stack_a;
		ft_printf("before swap\n");
		while (stack_a)
		{
			ft_printf("%d\n",stack_a->content);
			stack_a = stack_a->next;
		}
		ft_swap(&tmp);
		ft_printf("after rotate\n");
		while (tmp)
		{
			ft_printf("%d\n",tmp->content);
			tmp = tmp->next;
		}
		 ft_lstclear(&stack_a);
		ft_lstclear(&tmp);
	}
	else
		exit(EXIT_FAILURE);

}
