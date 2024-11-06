/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:42:52 by jacobmaizel       #+#    #+#             */
/*   Updated: 2024/10/16 12:30:12 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*i;
	const unsigned char	*j;

	i = (unsigned char *)dest;
	j = (const unsigned char *)src;
	if (n == 0 || dest == src)
		return (dest);
	while (n--)
		*i++ = *j++;
	return (dest);
}
/*
explication fonction :
copie n octets de la memoire pointe par src vers la memoire pointee par dest.
 elle renvoie dest si n est egal a 0 ou si dest 
 et src pointenet vers la meme zone memoire
*/

/*
int main ()
{
	void *dest;
	const void *src = "bojour";
	size_t n = 0;
	ft_memcpy(dest, src, n);
	printf("%s\n", dest);
	return (0);
}
*/