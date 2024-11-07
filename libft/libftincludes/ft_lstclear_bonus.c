/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:17:54 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/17 14:28:05 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		del((*lst)-> content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
/*
void del(void *content)
{
    free(content);
}
int main(void)
{
    t_list *elem1 = ft_lstnew("Chaîne 1");
    t_list *elem2 = ft_lstnew("Chaîne 2");
    t_list *elem3 = ft_lstnew("Chaîne 3");
    elem1->next = elem2;
    elem2->next = elem3;
    ft_lstclear(&elem1, del);
    if (elem1 == NULL)
        printf("La liste a été correctement effacée.\n");
    else
        printf("Il reste des éléments dans la liste.\n");
    return 0;
}
*/
/*
que fait la fonction : supprime l element passe en parametre ainsi
que tout les element del al liste chainee.

1. verifier si la liste ou la fonction del son valides
2. parcourrire lst a partir de l'element donne
3. supprime le contenu et l element lui-meme en utilisant del et free
4. met a jour le pointeur initial a NULL pour indiquer que tout 
les elelement sont supprime
*/