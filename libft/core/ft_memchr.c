/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:03:30 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/19 18:37:05 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*n_s;

	i = 0;
	n_s = (unsigned char *)s;
	while (i < n)
	{
		if (n_s[i] == (unsigned char)c)
			return ((unsigned char *)&n_s[i]);
		i++;
	}
	return (NULL);
}
