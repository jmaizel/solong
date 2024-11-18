/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:06:21 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/28 15:10:09 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(const char format, va_list args)
{
	int	size;

	size = 0;
	if (format == 'c')
		size += ft_print_char(args);
	else if (format == 'i' || format == 'd')
		size += ft_print_int(args);
	else if (format == 's')
		size += ft_print_str(args);
	else if (format == 'u')
		size += ft_print_unsigned(args);
	else if (format == 'x')
		size += ft_print_lowercase(args);
	else if (format == 'X')
		size += ft_print_highercase(args);
	else if (format == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else if (format == 'p')
		size += ft_print_pointeur(args);
	return (size);
}
