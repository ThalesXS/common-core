/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e <rsilva-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 23:08:51 by rsilva-e          #+#    #+#             */
/*   Updated: 2023/04/26 23:08:51 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = (t_list *)malloc(sizeof(t_list));
	if (element == NULL)
		return (NULL);
	element -> content = content;
	element -> next = NULL;
	return (element);
}
/*
int main()
{
	t_list *p;
	int *valor = malloc(sizeof(int));
	*valor = 7;
	p = ft_lstnew(valor);
	printf("%d",*(int*)p->content);
}*/
