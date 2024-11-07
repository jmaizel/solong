/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:42:58 by jacobmaizel       #+#    #+#             */
/*   Updated: 2024/10/17 14:21:01 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t count)
{
	unsigned char	*i;

	i = (unsigned char *)ptr;
	while (count > 0)
	{
		*i++ = (unsigned char)value;
		count--;
	}
	return (ptr);
}
/*
remplit une zone memie specifiee avec une valeur donnee. 
elle prend un pointeur vers la zone memoire,
 une valeure a ecrire et le nombre d octets a remplir.
*/

/*
#include <stdio.h>
#include <string.h>
int main() {
	char *buffer; 
	//ft_memset(NULL, '*', 5);
	buffer = memset(NULL, 5, 5);
	printf("%s\n", buffer);
	return 0;
}
*/