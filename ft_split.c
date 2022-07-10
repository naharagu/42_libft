/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 06:19:05 by naharagu          #+#    #+#             */
/*   Updated: 2022/07/10 17:39:03 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_charset(char a, char *charset)
{
	while (*charset)
	{
		if (a == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_strlen(char const *str, char *charset)
{
	int	count;

	count = 0;
	while (str[count] && !is_charset(str[count], charset))
		count++;
	return (count);
}

int	count_words(char const *str, char *charset)
{
	int	count;
	int	len_str;

	count = 0;
	while (*str)
	{
		while (*str && is_charset(*str, charset))
			str++;
		len_str = count_strlen(str, charset);
		str += len_str;
		if (len_str)
			count++;
	}
	return (count);
}

void	copy_str(char *dest, const char *start_str, const char *end_str)
{
	while (start_str < end_str)
	{
		*dest = *start_str;
		start_str++;
		dest++;
	}
	*dest = 0;
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	int			i;
	char const	*start_str;

	result = (char **)malloc(sizeof(char *) * (count_words(s, &c) + 1));
	i = 0;
	while (*s)
	{
		if (!is_charset(*s, &c))
		{
			start_str = s;
			while (*s && !is_charset(*s, &c))
				s++;
			result[i] = (char *)malloc(sizeof(char) * (s - start_str + 1));
			copy_str(result[i], start_str, s);
			i++;
		}
		s++;
	}
	result[i] = 0;
	return (result);
}
