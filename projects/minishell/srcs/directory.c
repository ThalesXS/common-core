/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:38:38 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/17 00:00:16 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_dir(t_minishell *minishell)
{
	char	*dir;
	char	*tmp;

	tmp = getcwd(NULL, 0);
	dir = ft_strjoin \
	("\001\033[1;32m\002minishell@42\001\033[0m\002:\001\033[1;34m\002", tmp);
	if (minishell->dir != NULL)
		free(minishell->dir);
	minishell->dir = ft_strjoin(dir, "\001\033[0m\002$ ");
	free(tmp);
	free(dir);
}
