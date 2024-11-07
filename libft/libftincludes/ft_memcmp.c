/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:31:17 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/16 12:05:24 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *) s1;
	str2 = (const unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
explication fonction :
compare deux blocs de memoire, elle examine examine jusqu a n octets s1 et s2.
 si une difference est trouvee,
  elle renvoie la difference ascii entre les octets corrrespondants.
*/

/*
int main ()
{
	const void *s1 = "bonjour";
	const void *s2 = "salut";
	size_t n = 10;
	int res;
	res = ft_memcmp(s1, s2, n);
	printf("%d\n", res);
	return (0);
}
*/