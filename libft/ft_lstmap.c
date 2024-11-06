/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaizel <jmaizel@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:48:48 by jmaizel           #+#    #+#             */
/*   Updated: 2024/10/17 14:14:48 by jmaizel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_obj;

	if (lst == NULL || del == NULL || f == NULL)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_obj = ft_lstnew(f(lst->content));
		if (new_obj == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_obj);
		lst = lst->next;
	}
	return (new_list);
}
/*
void *duplicate_content(void *content)
{
    return (ft_strdup((char *)content));
}

void print_list(t_list *lst)
{
    while (lst)
    {
        printf("voici le contenu : %s\n", (char *)lst->content);
        lst = lst->next;
    }
}

void del(void *content)
{
    free(content);
}
int main(void)
{

    t_list *list = ft_lstnew(ft_strdup("je suis jacob"));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("etudiant")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("a l'ecole 19")));


    t_list *new_list = ft_lstmap(list, duplicate_content, del);

    printf("Nouvelle liste après ft_lstmap :\n");
    print_list(new_list);

    ft_lstclear(&list, del);
    ft_lstclear(&new_list, del);

    return 0;
}
*/

/*
explication fonction :
parcourt une liste chainee, applique une fonction
donne (f) a chaque elemet et cree ue nouvelle liste contenant
les resultats.
si la creation d un nouvel element echoue,
on utilise une fonction de supression del

1. on verifie si lst del ou f sont NULL
2. on initialise la nouvelle liste et le nouvelle objet
3. parcour chaque element de la liste do4rigine
et on y qpplique la fonction f
4.on verifie si l application a fonctionne
5. si echec, on libere la nouvelle liste creer
jusqu a present
6.on ajoute un nouvel element a la fin de la nouvelle liste
7 on passsea l element suivant de la liste d origine
8. on renvoie la nouvelle liste.
*/
