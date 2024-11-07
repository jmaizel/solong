/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:09:52 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/17 14:00:55 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL && del != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
/*
void	del(void *content)
{
	free(content);
	printf ("contenu supprime\n");
}
int main ()
{
	t_list *elem = ft_lstnew(ft_strdup("string 1"));
	printf("contenut avant suppression : %s\n", (char *)elem->content);
	ft_lstdelone(elem, del);
	return (0);
}
*/
/*
1. verifier si l element et la fonction ne sont pas NULL
2. appliquer la fonction del pour liberer le contenu de l element
3.liberer la memoire de l element
*/