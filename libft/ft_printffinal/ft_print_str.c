/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:11:58 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/25 17:16:35 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}
