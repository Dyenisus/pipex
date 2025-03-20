/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:20:53 by yektasoytur       #+#    #+#             */
/*   Updated: 2025/03/19 19:45:15 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_format_type(char ftype, va_list args)
{
	int	count;

	count = 0;
	if (ftype == '\0')
		return (count);
	if (ftype == '%')
		count += char_printer('%');
	else if (ftype == 'c')
		count += char_printer_arg(args);
	else if (ftype == 's')
		count += str_printer_arg(args);
	else if (ftype == 'd' || ftype == 'i')
		count += ft_putnbr_arg(args, "0123456789");
	else if (ftype == 'u')
		count += ft_putunsigned(args, "0123456789");
	else if (ftype == 'x')
		count += ft_putunsigned(args, "0123456789abcdef");
	else if (ftype == 'X')
		count += ft_putunsigned(args, "0123456789ABCDEF");
	else if (ftype == 'p')
		count += ft_putadress(args, "0123456789abcdef");
	else
		count += char_printer(ftype);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += ft_format_type(s[i], args);
		}
		else
			count += char_printer(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
