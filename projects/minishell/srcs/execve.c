/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:36:02 by dmeirele          #+#    #+#             */
/*   Updated: 2024/02/21 13:36:09 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	ft_exec_command(char *command, t_parsed *tokens);
static char	**ft_count_args(t_parsed *tokens);
static char	*ft_get_absolut_path(char *command, t_envs *envs);
static char	*ft_get_relative_path(char *command);

static void	ft_exec_command(char *command, t_parsed *tokens)
{
	t_envs	*envs;
	pid_t	new_process;
	char	**array_env;
	char	**new_array;

	new_array = ft_count_args(tokens);
	envs = return_envs(0);
	array_env = ft_array_envs(envs);
	new_process = fork();
	if (!new_process)
	{
		if (execve(command, new_array, array_env) == -1)
		{
			free_splits(new_array);
			free_splits(array_env);
			free(command);
			ft_exit(tokens);
		}
	}
	else
		waitpid(-1, NULL, 0);
	free(command);
	free_splits(new_array);
	free_splits(array_env);
}

static char	**ft_count_args(t_parsed *tokens)
{
	int			i;
	char		**new;
	t_parsed	*head;

	i = 0;
	head = tokens;
	while (tokens && tokens->type != PIPE)
	{
		i++;
		tokens = tokens->next;
	}
	new = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (head && head->type != PIPE)
	{
		new[i] = ft_strdup(head->text);
		i++;
		head = head->next;
	}
	new[i] = NULL;
	return (new);
}

static char	*ft_get_absolut_path(char *command, t_envs *envs)
{
	char	**path;
	char	*temp;
	char	*exec;
	int		i;

	i = -1;
	if (access(command, X_OK) == 0)
		return (ft_strdup(command));
	path = ft_get_path(envs);
	while (path[++i])
	{
		temp = ft_strjoin(path[i], "/");
		exec = ft_strjoin(temp, command);
		free(temp);
		if (access(exec, X_OK) == 0)
		{
			free_splits(path);
			return (exec);
		}
		free(exec);
	}
	return (free_splits(path), NULL);
}

static char	*ft_get_relative_path(char *command)
{
	char	*curr_dir;
	char	*relative_path;
	char	*temp;

	curr_dir = getcwd(NULL, 0);
	temp = ft_strjoin(curr_dir, "/");
	relative_path = ft_strjoin(temp, command);
	free(temp);
	free(curr_dir);
	return (relative_path);
}

void	ft_find_path(t_parsed *token, t_envs *envs)
{
	char	*command;
	char	*path;

	command = ft_strdup(token->text);
	path = NULL;
	if (!ft_strncmp(command, "./", 2))
		path = ft_get_relative_path(command);
	else
		path = ft_get_absolut_path(command, envs);
	if (path)
		ft_exec_command(path, token);
	else
		printf("%s: No such file or directory\n", command);
	free(command);
}
