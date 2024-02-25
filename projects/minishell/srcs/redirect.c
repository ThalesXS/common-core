/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:08:49 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/25 01:07:53 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	ft_overwrite(t_parsed **aux, t_parsed **tokens, int num_com);
static void	ft_append(t_parsed **aux, t_parsed **tokens, int num_com);
static void	ft_input(t_parsed **aux, t_parsed **tokens, int num_com);
static void	ft_heredoc(t_parsed **aux, t_parsed **tokens, int num_com);

void	ft_redirect(t_parsed **tokens, int num_com)
{
	t_parsed	*aux;

	aux = tokens[num_com];
	while (aux)
	{
		if (aux->type == RD_OVERWRITE)
			ft_overwrite(&aux, tokens, num_com);
		else if (aux->type == RD_APPEND)
			ft_append(&aux, tokens, num_com);
		else if (aux->type == RD_INPUT)
			ft_input(&aux, tokens, num_com);
		else if (aux->type == RD_HEREDOC)
			ft_heredoc(&aux, tokens, num_com);
		if (aux)
			aux = aux->next;
	}
}

static void	ft_overwrite(t_parsed **aux, t_parsed **tokens, int num_com)
{
	int			fd;
	t_parsed	*tmp;
	t_parsed	*free_me;

	tmp = (*aux)->prev;
	free_me = *aux;
	*aux = (*aux)->next->next;
	fd = open(free_me->next->text, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, 1);
	close(fd);
	free_me->next->next = NULL;
	if (tmp)
	{
		tmp->next = *aux;
		if ((*aux))
			(*aux)->prev = tmp;
	}
	else
		tokens[num_com] = *aux;
	ft_free_tokens(free_me);
}

static void	ft_append(t_parsed **aux, t_parsed **tokens, int num_com)
{
	int	fd;
	t_parsed	*tmp;
	t_parsed	*free_me;

	tmp = (*aux)->prev;
	free_me = *aux;
	*aux = (*aux)->next->next;
	fd = open(free_me->next->text, O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd, 1);
	close(fd);
	free_me->next->next = NULL;
	if (tmp)
	{
		tmp->next = *aux;
		if ((*aux))
			(*aux)->prev = tmp;
	}
	else
		tokens[num_com] = *aux;
	ft_free_tokens(free_me);
}

static void	ft_input(t_parsed **aux, t_parsed **tokens, int num_com)
{
	int	fd;
	t_parsed	*tmp;
	t_parsed	*free_me;

	tmp = (*aux)->prev;
	free_me = *aux;
	*aux = (*aux)->next->next;
	fd = open(free_me->next->text, O_RDONLY);
	dup2(fd, 0);
	close(fd);
	free_me->next->next = NULL;
	if (tmp)
	{
		tmp->next = *aux;
		if ((*aux))
			(*aux)->prev = tmp;
	}
	else
		tokens[num_com] = *aux;
	ft_free_tokens(free_me);
}

static void	ft_heredoc(t_parsed **aux, t_parsed **tokens, int num_com)
{
	int		pipe_fd[2];
	int		status;
	char	*line;
	t_parsed	*tmp;
	t_parsed	*free_me;

	tmp = (*aux)->prev;
	free_me = *aux;
	*aux = (*aux)->next->next;
	status = pipe(pipe_fd);
	if (status == -1)
		ft_printf("Error creating pipe\n");
	while (1)
	{
		line = readline("> ");
		if (!ft_strcmp(line, free_me->next->text))
			break ;
		status = write(pipe_fd[1], line, ft_strlen(line));
		status = write(pipe_fd[1], "\n", 1);
		free(line);
	}
	close(pipe_fd[1]);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	free_me->next->next = NULL;
	if (tmp)
	{
		tmp->next = *aux;
		if ((*aux))
			(*aux)->prev = tmp;
	}
	else
		tokens[num_com] = *aux;
	ft_free_tokens(free_me);
}
