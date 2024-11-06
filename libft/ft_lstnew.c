/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:41:07 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/17 13:42:56 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}
/*
explication fonction :
alloue un nouvel element de type t_list et initialise
 son contenu avec la valeur fournie content.
met egalement le pointeur nex a null.
*/
/*
int main ()
{
	void *content = "bonjour";
	t_list *dest;
	dest = ft_lstnew(content);
	printf("%s\n",(char *)dest->content);
	return (0);
}
*/