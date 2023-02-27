/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:03:04 by hasserao          #+#    #+#             */
/*   Updated: 2023/02/27 02:51:48 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = malloc (sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = *lst;
		while (last -> next != NULL)
			last = last -> next;
		last -> next = new;
	}
}
void ft_lstclear(t_list **lst)
{
	t_list *curr;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		curr = (*lst)->next;
		free(*lst);
		*lst = curr;
	}
	*lst = NULL;
}
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
