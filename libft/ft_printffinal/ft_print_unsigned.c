/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:28:15 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/23 15:35:20 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_putnbr_unsigned(unsigned int n)
{
	int	result;

	result = 0;
	if (n > 9)
		result += ft_putnbr_unsigned(n / 10);
	ft_putchar(n % 10 + '0');
	return (result + 1);
}

int	ft_print_unsigned(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	return (ft_putnbr_unsigned(nb));
}
