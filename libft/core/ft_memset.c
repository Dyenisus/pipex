/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:06:43 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/19 18:37:20 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*e;

	e = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		e[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
