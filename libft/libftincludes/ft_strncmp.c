/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:38:03 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/16 12:22:27 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
explication fonctiom :
compare s1 et s2 jusqu a n.
elle retourn un entiere qui indique la relation lexxicographique
 entre les deux chaines. 
*/

/*
int main ()
{
	const char *s1 = "test";
	const char *s2 = "";
	size_t n = 3;
	int res;
	res = ft_strncmp(s1, s2, n);
	printf("%d\n", res);
	return (0);
}
*/