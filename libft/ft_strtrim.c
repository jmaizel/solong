/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:25:20 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/17 11:13:37 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_charset(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static	size_t	get_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && is_charset(s1[start], set))
		start++;
	return (start);
}

static	size_t	get_end(char const *s1, char const *set)
{
	size_t	end;

	end = ft_strlen(s1);
	while (end > 0 && is_charset(s1[end - 1], set))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	tab = malloc(sizeof(char) * (end - start + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (start < end)
		tab[i++] = s1[start++];
	tab[i] = '\0';
	return (tab);
}
/*
explication fonction :
supprime tout les caracteres de debut et de fin
d une chaine donnee s1 qui appartiennent a un
ensemble de caracteres set.
si s1 ou set est NULL, 
la fonction renvoie NULL.
i tout les caracteres sont trouves,
une chaine vide est renvoyes,
sinon,
elle renvoie une nouvelle chaine contenant les cracteres restants

*/

/*
int main()
{
    char const *s1 = "nnnnnnnnbonnnnjour";
    char const *set = "n";
    char *res;

    res = ft_strtrim(NULL, NULL);
    printf("%s\n", res);
    free(res);
    return (0);
}
*/