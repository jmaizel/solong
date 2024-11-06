/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:03:42 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/17 11:35:09 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
extrait une sous-chaine d une chaine donnee s,
en commencant a un index start specifie et en prenant len caracteres.
*/

/*
int main ()
{
	char *res;
	char const *s = "bonjour";
	unsigned int start = 3;
	size_t len = 7;
	res = ft_substr(NULL, start, len);
	printf ("%s\n", res);
	free(res);
	return (0);
}
*/