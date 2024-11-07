/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:10:02 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/17 13:52:07 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
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

	ft_lstadd_front(&list, elem1);
	ft_lstadd_front(&list, elem2);
	ft_lstadd_front(&list, elem3);

	ft_print_list(list);	
}
*/