/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:22:29 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/28 16:17:11 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_format(const char *str, va_list args)
{
	int	i;
	int	res;
	int	temp_res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			temp_res = ft_check(str[i], args);
			res += temp_res;
		}
		else
		{
			write(1, &str[i], 1);
			res++;
		}
		i++;
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = ft_format(format, args);
	va_end(args);
	return (res);
}

#include <stdio.h>
int main()
{
	/* int n, m;
    n = ft_printf("Test: %d, %c, %s, %p, %x, %X, %%\n", 
	3, 'A', "Hello", &main, 255, 255);
	m = printf("Test: %d, %c, %s, %p, %x, %X, %%\n", 
	3, 'A', "Hello", &main, 255, 255);
	printf("%d vs %d\n", n, m); */
	printf ("%c", '0');
    return 0;
}
