/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointeur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:17:53 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/23 15:33:32 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static	int	ft_nbrlen(unsigned long nb)
{
	int	compt;

	compt = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		compt++;
	}
	return (compt);
}

static	void	ft_putnbr_hex(unsigned long nb)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (nb >= 16)
		ft_putnbr_hex(nb / 16);
	ft_putchar(hex_digits[nb % 16]);
}

int	ft_print_pointeur(va_list args)
{
	void			*pointeur;
	unsigned long	nb;

	pointeur = va_arg(args, void *);
	if (!pointeur)
		return (write(1, "0x0", 3));
	nb = (unsigned long) pointeur;
	write(1, "0x", 2);
	ft_putnbr_hex(nb);
	return (ft_nbrlen(nb) + 2);
}
