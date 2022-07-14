/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 06:19:05 by naharagu          #+#    #+#             */
/*   Updated: 2022/07/14 08:41:52 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst > src)
		i = len + 1;
	else
		i = -1;
	if (dst != src && len)
	{
		if (dst > src)
			while (--i)
				((unsigned char *)dst)[i - 1] = ((const unsigned char *)src)[i - 1];
		else
			while (++i < len)
				((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
	}
	return (dst);
}
