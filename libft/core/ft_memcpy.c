/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:04:44 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/19 18:37:14 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*n_dst;
	unsigned char	*n_src;

	if (!dst && !src)
		return (NULL);
	n_dst = (unsigned char *)dst;
	n_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		n_dst[i] = n_src[i];
		i++;
	}
	return (dst);
}
