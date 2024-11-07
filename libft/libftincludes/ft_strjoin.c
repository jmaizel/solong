/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:10:53 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/17 11:48:06 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*tab;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tab)
		return (0);
	while (i < ft_strlen(s1))
	{
		tab[i + j] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		tab[i + j] = s2[j];
		j++;
	}
	tab[i + j] = '\0';
	return (tab);
}
/*
int main ()
{
	char const *s1 = "bonjour";
	char const *s2 = "salut";
	char *res;
	res = ft_strjoin(NULL, s2);
	printf ("%s\n", res);
	return (0);
	free(res);
}
*/