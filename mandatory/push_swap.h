/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:17:02 by hasserao          #+#    #+#             */
/*   Updated: 2023/03/15 18:25:16 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				pos;
	int				index;
	int				bott;
	int				top;
	int				md;
	int				min;
	int				max;
	int				b_max;
	int				min_pos;
	int				max_pos;
	int				md_pos;
	int				size;
	int				chunk;
	struct s_list	*next;
}					t_list;

void				ft_error_msg(char *str);
size_t				ft_strlen(const char *s);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strdup(const char *s1);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strjoin(char *s1, char *s2);
char				**free_strings(char **str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
long				ft_atoi(char *str);
char				**ft_parsing(int argc, char **argv);
t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
void				ft_lstclear(t_list **lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_get_list(int argc, char **argv, t_list **stack_a);
void				index_list(t_list **stack, t_list *new);
int					is_sorted(t_list **stack);
void				init_stack(t_list **stack);
void				ft_swap_a(t_list **stack);
void				ft_rotate_a(t_list **stack);
void				ft_reverse_rotate_a(t_list **stack);
void				ft_push_a(t_list **b, t_list **a);
void				ft_swap_b(t_list **stack);
void				ft_rotate_b(t_list **stack);
void				ft_reverse_rotate_b(t_list **stack);
void				ft_push_b(t_list **b, t_list **a);
void				sort_under(t_list **stack);
void				sort_three(t_list **stack);
void				lst_min(t_list **stack);
void				lst_max(t_list **stack);
void				ft_init_pos(t_list **stack);
int					ft_get_min_pos(t_list **stack);
int					ft_get_pos(t_list *stack, int index);
void				move_min_to_top(t_list **stack);
void				sort_five(t_list **a, t_list **b);
void				chunk_sort(t_list **a, t_list **b, int d);

#endif
