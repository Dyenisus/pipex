/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:04:06 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/19 18:37:08 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*n_s1;
	unsigned char	*n_s2;

	i = 0;
	n_s1 = (unsigned char *)s1;
	n_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (n_s1[i] != n_s2[i])
			return (n_s1[i] - n_s2[i]);
		i++;
	}
	return (0);
}
