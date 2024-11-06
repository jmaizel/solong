/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:36:53 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/17 11:23:38 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	compter(int nb)
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

char	*ft_itoa(int nb)
{
	int		length;
	char	*tab;

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	length = compter(nb);
	tab = malloc(sizeof(char) * (length + 1));
	if (!tab)
		return (0);
	tab[length] = '\0';
	if (nb == 0)
		tab[0] = '0';
	if (nb < 0)
	{
		tab[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		tab[--length] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (tab);
}
/*
int main()
{
	int nb = -10004;
	char *res = ft_itoa(2334);
	printf("%s\n", res);
	free(res);
	return 0;
}
*/
