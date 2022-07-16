/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 23:20:33 by naharagu          #+#    #+#             */
/*   Updated: 2022/07/16 17:49:44 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dest);
	if (!dstsize)
		return (src_len);
	else if (dst_len > dstsize)
		src_len += dstsize;
	else
	{
		src_len += dst_len;
		ft_strlcpy(dest + dst_len, src, dstsize - dst_len);
	}
	return (src_len);
}
