/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:27:07 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/16 19:31:17 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_input_validator(t_minishell *minishell)
{
	int i;
	char *tmp;

	i = 0;
	tmp = minishell->input;
	while (tmp[i])
	{
		if (tmp[i] == ' ')
			return (1);
		i++;
	}
}

int	ft_quotes_validator(char *str)
{
	
}