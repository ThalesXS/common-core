/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:38:38 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/16 19:53:48 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_dir(t_minishell *minishell)
{
	char	*dir;
	char	*tmp;

	tmp = getcwd(NULL, 0);
	dir = ft_strjoin("\033[1;32mminishell\033[0m:\033[1;34m", tmp);
	if (minishell->dir != NULL)
		free(minishell->dir);
	minishell->dir = ft_strjoin(dir, "\033[0m$ ");
	free(tmp);
	free(dir);
}