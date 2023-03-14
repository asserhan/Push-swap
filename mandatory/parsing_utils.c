/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasserao <hasserao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:43:33 by hasserao          #+#    #+#             */
/*   Updated: 2023/03/14 20:53:23 by hasserao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	size;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	size = i + 1;
	p = (char *)malloc(size * sizeof(char));
	if (!p || !s1)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)p)[i] = ((char *)s1)[i];
		i++;
	}
	return (p);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l_dst;
	size_t	l_src;

	l_src = ft_strlen(src);
	i = 0;
	if (dstsize == 0 && !dst)
		return (l_src);
	l_dst = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= l_dst)
		return (l_src + dstsize);
	while (src[i] && (i + l_dst) < dstsize - 1)
	{
		dst[l_dst + i] = src[i];
		i++;
	}
	dst[l_dst + i] = '\0';
	return (l_dst + l_src);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(len + 1 * sizeof(char));
	if (!p)
		return (NULL);
	else
	{
		ft_strlcpy(p, s1, ft_strlen(s1) + 1);
		ft_strlcat(p, s2, len + 1);
	}
	free(s1);
	return (p);
}
