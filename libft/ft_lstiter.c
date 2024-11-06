/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:40:51 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/17 14:06:19 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (lst == NULL)
		return ;
	current = lst;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
}
/*
void	print(void *content)
{
	printf("impression du contenu : %s\n", (char *)content);
}
int main ()
{
	t_list *list = ft_lstnew(ft_strdup("salut je suis jacob"));
	ft_lstiter(list, print);
	return (0);
}
*/

/*
explication fonction :
permet de parcourir chaque element d une liste chainee,
 en appliquant une fonction sp2cifi2 (f)
*/