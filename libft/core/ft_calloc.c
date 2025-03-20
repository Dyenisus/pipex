/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:48:34 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/19 18:36:09 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	a = (void *)malloc(count * size);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, count * size);
	return (a);
}
