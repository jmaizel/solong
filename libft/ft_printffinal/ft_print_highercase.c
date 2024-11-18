/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_highercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:27:50 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/23 15:33:21 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_nbrlen(unsigned int nb)
{
	int	compt;

	compt = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 16;
		compt++;
	}
	return (compt);
}

static void	div_putnbr_hex(unsigned int nb)
{
	char	*hex_digits;
	char	result[8];
	int		i;

	i = 0;
	hex_digits = "0123456789ABCDEF";
	if (nb == 0)
		ft_putchar('0');
	while (nb > 0)
	{
		result[i] = hex_digits[nb % 16];
		nb /= 16;
		i++;
	}
	while (--i >= 0)
		ft_putchar(result[i]);
}

int	ft_print_highercase(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	div_putnbr_hex(nb);
	return (ft_nbrlen(nb));
}
