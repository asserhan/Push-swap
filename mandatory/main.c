/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:46:53 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/19 19:01:19 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc,char **argv)
{
	if (argc >= 2)
	{
		char **s;
		s = ft_parsing(argc,argv);
		check_input(s);

		while (*s)
		{
			ft_printf("%s\n",*s);
			s++;
		}
		// system("leaks push_swap");
	}
	else
		exit(EXIT_FAILURE);

}
