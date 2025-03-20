/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:13:11 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/19 18:37:41 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	chr;

	chr = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == chr)
			return ((char *)&s[i]);
		i++;
	}
	if (chr == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
