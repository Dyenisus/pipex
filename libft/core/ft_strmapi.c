/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:16:59 by yesoytur          #+#    #+#             */
/*   Updated: 2025/03/19 18:38:05 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*a;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	a = (char *)malloc((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	i = 0;
	while (s[i])
	{
		a[i] = f(i, s[i]);
		i++;
	}
	a[len] = '\0';
	return (a);
}
