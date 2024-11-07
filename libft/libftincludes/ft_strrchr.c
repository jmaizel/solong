/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:12:08 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/16 12:25:56 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = ft_strlen(s);
	uc = (unsigned char)c;
	if (uc == '\0')
		return ((char *)&s[i]);
	while (i > 0)
	{
		if ((unsigned char)s[i - 1] == uc)
			return ((char *)&s[i - 1]);
		i--;
	}
	return (0);
}
/*
recherce la derniere occurence d un caractere
specifie c dans une chaine s.
si le caractere est trouve,
la fonction retourne un pointeur vers cette occurrence
si le caractere n est pas trouve,
la fonction renvoie NULL
*/

/*
int main ()
{
	const char *s = "bonjour je suis jacob";
	int c = 'b';
	char *res;
	res = ft_strrchr(s, c);
	printf ("%s\n", res);
	return (0);
}
*/
