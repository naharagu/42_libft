/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 06:19:05 by naharagu          #+#    #+#             */
/*   Updated: 2022/07/10 13:01:39 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		++s;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (ft_isdigit(*s))
	{
		if ((res >= 0) != ((res << 1) >= 0) || \
			(res >= 0) != ((res << 2) >= 0) || \
			(res >= 0) != ((res << 3) >= 0) || \
			(res >= 0) != (res * 10 + (*s - '0') >= 0))
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		res = res * 10 + (*s++ - '0');
	}
	return (res * sign);
}
