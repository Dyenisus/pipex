/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:20:48 by yektasoytur       #+#    #+#             */
/*   Updated: 2025/03/19 19:45:26 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

int	char_printer(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	char_printer_arg(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (char_printer(c));
}

int	str_printer_arg(va_list args)
{
	int		count;
	int		i;
	char	*s;

	s = ft_strdup(va_arg(args, char *));
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = 0;
	i = 0;
	while (s[i])
	{
		count += char_printer(s[i]);
		i++;
	}
	free(s);
	return (count);
}
