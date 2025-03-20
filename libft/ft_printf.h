/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:19:50 by yektasoytur       #+#    #+#             */
/*   Updated: 2025/03/19 19:56:08 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *s, ...);
int	char_printer(char c);
int	char_printer_arg(va_list args);
int	str_printer_arg(va_list args);
int	ft_putnbr_arg(va_list args, char *base);
int	ft_putunsigned(va_list args, char *base);
int	ft_putadress(va_list args, char *base);

#endif