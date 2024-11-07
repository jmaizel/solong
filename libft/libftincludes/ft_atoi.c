/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:09:13 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/17 13:27:59 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (nb > 9223372036854775807 && sign == 1)
		return (-1);
	if (nb > 9223372036854775807 && sign == -1)
		return (0);
	return (nb * sign);
}
/*
int	main(void)
{
	const char	*str = "945";
	int			res;

	res = ft_atoi(str);
	printf("%d\n", res);
	printf("%d\n", atoi(str));
	return (0);
}
*/