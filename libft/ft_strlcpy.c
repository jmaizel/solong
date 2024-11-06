/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:43:01 by jacobmaizel       #+#    #+#             */
/*   Updated: 2024/10/16 12:18:54 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
/*
copie une chaine src dans une chaine dst
tout en s assurant de ne pas depasser la taille specifie de dst
*/

/*
int main ()
{
	char dst[50];
	const char *src = "bonjour";
	size_t dstsize = 10;
	size_t res;
	res = ft_strlcpy(dst, src, dstsize);
	printf("%zu\n", res);
	return 0;
}
*/