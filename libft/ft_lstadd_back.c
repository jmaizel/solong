/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:01:00 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/17 13:50:27 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}
/*
void ft_print_list(t_list *lst)
{
    while (lst != NULL)
    {
        printf("Contenu : %s\n", (char *)lst->content);
        lst = lst->next;
    }
}

int main ()
{
	t_list*list = NULL;

	t_list *elem1 = ft_lstnew("string 1");
	t_list *elem2 = ft_lstnew("string 2");
	t_list *elem3 = ft_lstnew("string 3");

	ft_lstadd_back(&list, elem1);
	ft_lstadd_back(&list, elem2);
	ft_lstadd_back(&list, elem3);

	ft_print_list(list);	
}
*/
/*
explication fonction :
ajoute un nouvel element new a la fin dune liste chainee.
1. si la liste est vide, le nouvel element devient
 le premier element de la liste 
2.temp prend la valeur du premier element de la liste.
 ensuit on parcour la liste jusqu au dernier element,
 une fois qu on l a atteint on attache le nouvel element a la fin de la liste.
*/
