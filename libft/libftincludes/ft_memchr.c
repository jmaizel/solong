/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:52:10 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/17 14:19:07 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
explication fonction :
recherche la premiere occurence d un caractere specifie.
 elle parcourt jusqu a n octets de la memoire pointe par s.
 et si elle trouve c elle renvoie un pointeur vers cet emplacement.
*/

/*
int main()
{
	const char *s = "nonjour je suis jacob";
	int c = 'u';
	size_t n = 50; 
	char *result = ft_memchr(s, c, n);
	if (result != NULL)
		printf("Caractère trouvé : %c\n", *result);
	else
		printf("Caractère non trouvé\n");
	return 0;
}
*/