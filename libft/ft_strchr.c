/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:29:07 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/16 12:14:00 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (s[i])
	{
		if ((unsigned char)s[i] == uc)
			return ((char *)&s[i]);
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return (0);
}
/*
explication fonction :
recherche la premiere occurence d un caractere dans une chaine de caractere.
elle prend une chaine s et un caractere c 
et renvoie un pointeur vers la premiere occurence de ce caractere dans la chaine.
*/

/*
int main ()
{
	const char *s = "bonjour je suis jacob";
	int c = 'u';
	char *res;
	res = ft_strchr(s, c);
	printf("%s\n", res);
	return (0);
}
*/
