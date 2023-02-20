/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:17:02 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/20 18:28:53 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_list
{
	int content;
	int position;
	struct s_list *next;
}			t_list;

void	ft_error_msg(char *str);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char  *s1, char *s2);
char	**free_strings(char **str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
long	ft_atoi(char *str);
char **ft_parsing(int argc,char **argv);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstclear(t_list **lst);
void check_input(t_list **stack_a,char **list);

#endif
