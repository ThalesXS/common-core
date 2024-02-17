/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 00:18:18 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/17 00:01:40 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_minishell	minishell;

	(void) argc;
	(void) argv;
	minishell.envp = envp;
	minishell.dir = NULL;
	ft_loop(&minishell);
	return (0);
}

void	ft_loop(t_minishell *minishell)
{
	while (1)
	{
		ft_get_dir(minishell);
		minishell->input = readline(minishell->dir);
		if (minishell->input == NULL)
			break ;
		if (minishell->input[0] != '\0')
		{
			add_history(minishell->input);
			minishell->tokens = ft_split(minishell->input, ' ');
			if (minishell->tokens == NULL)
				exit(1);
			//ft_token_validator(minishell);
			ft_token_handler(minishell);
			free(minishell->tokens);
			free(minishell->input);
		}
	}
}

void	ft_token_handler(t_minishell *minishell)
{
	int	i;

	i = 0;
	while (minishell->tokens[i])
	{
		printf("Token %d: %s\n", i, minishell->tokens[i]);
		i++;
	}
}
