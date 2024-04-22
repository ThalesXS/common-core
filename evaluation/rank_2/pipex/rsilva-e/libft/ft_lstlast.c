/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:19:22 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/26 23:19:22 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
/*
int main()
{
	t_list *list = NULL;
	t_list *last = NULL;

	int value = 1;
	int value1 = 2;
	int value2 = 3;
 

    // criar uma lista simplesmente encadeada com 3 elementos
	list = (t_list*)malloc(sizeof(t_list));
	list->content = &value;
	list->next = (t_list*)malloc(sizeof(t_list));
	list->next->content = &value1;
	list->next->next = (t_list*)malloc(sizeof(t_list));
	list->next->next->content = &value2;
	list->next->next->next = NULL;

    // encontrar o último elemento da lista usando a função ft_lstlast
	last = ft_lstlast(list);

    // imprimir o valor do último elemento
	printf("O último elemento da lista é: %d\n",*(int *) last->content);

    // liberar a memória alocada para a lista
	free(list->next->next);
	free(list->next);
	free(list);

	return 0;
}*/