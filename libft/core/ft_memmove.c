/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:05:52 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/19 18:37:17 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*n_dest;
	const unsigned char	*n_src;

	n_dest = (unsigned char *)dst;
	n_src = (const unsigned char *)src;
	if (n_dest == n_src || len == 0)
		return (dst);
	if (n_dest < n_src)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	i = len;
	while (i > 0)
	{
		n_dest[i - 1] = n_src[i - 1];
		i--;
	}
	return (dst);
}
