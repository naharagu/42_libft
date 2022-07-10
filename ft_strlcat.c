/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naharagu <naharagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 23:20:33 by naharagu          #+#    #+#             */
/*   Updated: 2022/04/28 02:23:35 by naharagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int	k;

	k = 0;
	while (str[k] != '\0')
		k++;
	return (k);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_dest;
	unsigned int	len_src;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
		j++;
	len_dest = j;
	len_src = ft_strlen(src);
	if (size < len_dest || size == 0)
		return (size + len_src);
	while (src[i] != '\0' && i < size - len_dest - 1)
	{
		dest[i] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (len_dest + len_src);
}
