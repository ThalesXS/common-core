/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 23:18:07 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/30 22:19:57 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*
int main(void)
{
    // Criando a lista vazia
    t_list *lst = NULL;

    // Adicionando elementos no final da lista
    ft_lstadd_back(&lst, ft_lstnew("foo"));
    ft_lstadd_back(&lst, ft_lstnew("bar"));
    ft_lstadd_back(&lst, ft_lstnew("baz"));

    // Imprimindo os elementos da lista
    t_list *current = lst;
    while (current != NULL)
    {
        printf("%s\n", (char *) current->content);
        current = current->next;
    }

    // Limpando a lista
    ft_lstclear(&lst, free);

    return 0;
}*/