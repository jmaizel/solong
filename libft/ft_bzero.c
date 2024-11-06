/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:42:24 by jacobmaizel       #+#    #+#             */
/*   Updated: 2024/10/16 11:51:09 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*i;

	i = (unsigned char *)s;
	while (n > 0)
	{
		*i++ = 0;
		n--;
	}
}
/*
explication fonction : prend un pointeur s et une taille n 
et met a zero les n premier octets
*/
