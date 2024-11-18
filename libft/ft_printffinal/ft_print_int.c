/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:00:30 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/24 15:19:17 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_nbrlen(int nb)
{
	int	compt;

	compt = 0;
	if (nb == 0)
		return (1);
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb = -nb;
		compt++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		compt++;
	}
	return (compt);
}

static	void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static	void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	ft_print_int(va_list args)
{
	int	nb;

	nb = va_arg(args, int);
	ft_putnbr(nb);
	return (ft_nbrlen(nb));
}
