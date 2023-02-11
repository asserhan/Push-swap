/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:00:14 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/11 19:05:47 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_msg(char *str)
{
	ft_printf("%s\n",str);
	exit(1);
}
int	ft_atoi(char *str)
{
	int i;
	int sign;
	long res;

	i =0;
	sign =1;
	res =0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign=-1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '-' || str[i] == '+')
		ft_error_msg("Error");
	while (str[i] && (str[i] >= '0'&& str[i] <= '9'))
	{

		res *=10;
		res += str[i] - '0';
		i++;
	}
	if (str[i])
			ft_error_msg("Error");
	return(res*sign);
}
char **get_args(int argc,char **argv)
{
	
}
char *ft_parsing(int argc,char **argv)
{
	if (argc > 2)
	{
		int i ;
		char *res;
		char *tmp;
		char *res_temp;

		i = 0;
		tmp = ft_strdup("");
		while (++i < argc)
		{
			res_temp =ft_strjoin(tmp,argv[i]);
			res = ft_strjoin(res_temp," ");
			tmp = res;
		}
		return (res);
	}
	else
		exit(1);
}

int main(int argc,char **argv)
{
	char *s;
	s = ft_parsing(argc,argv);
	ft_printf("%s\n",s);
	free(s);
	system("leaks push_swap");
}



// whiel (Ss)
// 	atoi(ss[i]);


// whiel (Ss)
// 	ls_addback(lst, lstnew(atoi(ss[i])));
