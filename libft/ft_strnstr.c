/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:49:41 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/16 12:24:26 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (0);
}
/*
explication fonction :
recherche la premiere occurence de la chaine needle
dans la chaine haystack
en limitant la recherche a len caracters de haystack.
si needle est une chaine vide, 
la fonction renvoie un pointeur vers le devut de haystack.
si needle n est pas trouvee dans haystack,
renvoie null
*/

/*
int main ()
{
	const char *haystack = "1";
	const char *needle = "";
	size_t len = 1;
	char *res = ft_strnstr(haystack, needle, len);
	printf("%s\n", res);
	return (0);
}
*/