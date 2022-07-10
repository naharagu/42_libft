/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 23:20:33 by naharagu          #+#    #+#             */
/*   Updated: 2022/07/10 13:27:58 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	else if (dstsize < ft_strlen(dest))
		len += dstsize;
	else
		len += ft_strlen(dest);
	while (dest[i])
		++i;
	while (src[j] && i < dstsize - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (len);
}
