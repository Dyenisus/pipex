/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:13:18 by yektasoytur       #+#    #+#             */
/*   Updated: 2025/03/19 19:45:30 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

static int	ft_number_based(unsigned long nbr, char *base, int count)
{
	unsigned int	base_length;

	base_length = ft_strlen(base);
	if (nbr >= base_length)
		count += ft_number_based(nbr / base_length, base, count);
	char_printer(base[nbr % base_length]);
	return (count + 1);
}

int	ft_putnbr_arg(va_list args, char *base)
{
	long	nbr;
	int		count;

	count = 0;
	nbr = va_arg(args, int);
	if (nbr < 0)
	{
		nbr = -nbr;
		count += char_printer('-');
	}
	count += ft_number_based(nbr, base, count);
	return (count);
}

int	ft_putunsigned(va_list args, char *base)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	nbr = va_arg(args, unsigned int);
	count += ft_number_based(nbr, base, count);
	return (count);
}

int	ft_putadress(va_list args, char *base)
{
	int				count;
	void			*check;
	unsigned long	nbr;

	check = va_arg(args, void *);
	if (!check)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	nbr = (unsigned long)check;
	ft_putstr_fd("0x", 1);
	count = 2;
	count += ft_number_based(nbr, base, count);
	return (count);
}
