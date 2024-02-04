/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e < rsilva-e@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:28:39 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/09/23 16:18:23 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*last;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst != NULL)
	{
		last = (*lst)->next;
		ft_lstdelone (*lst, del);
		*lst = last;
	}
	*lst = 0;
}
/*
int main(void)
{
	t_list *lst = NULL;

	// Adiciona alguns elementos à lista
	ft_lstadd_front(&lst, ft_lstnew("Hello"));
	ft_lstadd_front(&lst, ft_lstnew("world!"));
	ft_lstadd_front(&lst, ft_lstnew("My"));
	ft_lstadd_front(&lst, ft_lstnew("name"));
	ft_lstadd_front(&lst, ft_lstnew("is"));
	ft_lstadd_front(&lst, ft_lstnew("John"));

	// Imprime a lista antes de liberar a memória
	printf("Lista antes de liberar a memória:\n");
	while (lst != NULL)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}

	// Libera a memória da lista
	ft_lstclear(&lst, free);

	// Imprime a lista depois de liberar a memória
	printf("\nLista depois de liberar a memória:\n");
	while (lst != NULL)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}

	return (0);
}*/