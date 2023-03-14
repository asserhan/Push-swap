/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:00:14 by hasserao          #+#    #+#             */
/*   Updated: 2023/03/14 20:57:42 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_empty(char *argv)
{
	size_t	len;
	size_t	count;
	size_t	i;

	len = ft_strlen(argv);
	if (len == 0)
		return (1);
	count = 0;
	i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			count++;
		i++;
	}
	if (len == count)
		return (1);
	return (0);
}

int	ft_duplicate(char **list)
{
	int	i;
	int	j;

	i = 0;
	while (list[i])
	{
		j = i + 1;
		while (list[j])
		{
			if (ft_atoi(list[i]) == ft_atoi(list[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_limits(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		if ((ft_atoi(list[i]) > 2147483647) || (ft_atoi(list[i]) < -2147483648))
			ft_error_msg("Error");
		i++;
	}
}

char	*ft_get_args(int argc, char **argv)
{
	int		i;
	char	*res;
	char	*tmp;
	char	*res_temp;

	i = 0;
	tmp = ft_strdup("");
	while (++i < argc)
	{
		if (ft_is_empty(argv[i]))
			ft_error_msg("Error");
		res_temp = ft_strjoin(tmp, argv[i]);
		res = ft_strjoin(res_temp, " ");
		tmp = res;
	}
	return (res);
}

char	**ft_parsing(int argc, char **argv)
{
	char	**list;
	char	*res;

	res = ft_get_args(argc, argv);
	list = ft_split(res, ' ');
	free(res);
	if (!list)
	{
		free_strings(list);
		ft_error_msg("split Error");
	}
	if (ft_duplicate(list))
		ft_error_msg("Error");
	ft_limits(list);
	return (list);
}
