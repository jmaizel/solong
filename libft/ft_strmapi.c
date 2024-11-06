/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:11:21 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/16 12:20:21 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char*s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len_s;
	char	*tab;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	tab = malloc(sizeof(char) * (len_s + 1));
	if (!tab)
		return (NULL);
	while (i < len_s)
	{
		tab[i] = f(i, s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
/*
explication fonction : 
creer une nouvelle chaine de caractere
en appliquant une fonction donnee a chaque caractere
d une chaine d entree
*/
