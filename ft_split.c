/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 06:19:05 by naharagu          #+#    #+#             */
/*   Updated: 2022/07/14 18:26:53 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

char	**free_dst(char **dst, size_t i)
{
	while (i >= 0)
	{
		free (dst[i]);
		dst[i--] = NULL;
	}
	free (dst);
	dst = NULL;
	return (dst);
}

char	**split_helper(char **dst, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			len++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			dst[j] = (char *)malloc(sizeof(char) * (len + 1));
			if (!dst)
				return (free_dst (dst, j));
			ft_strlcpy (dst[j], &s[i - len + 1], len + 1);
			j++;
			len = 0;
		}
		i++;
	}
	dst[j] = NULL;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	size_t	count;

	if (s == NULL)
		return (NULL);
	count = count_word(s, c);
	dst = (char **)malloc(sizeof(char *) * (count + 1));
	if (!dst)
		return (NULL);
	if (!split_helper (dst, s, c))
		return (NULL);
	return (dst);
}
