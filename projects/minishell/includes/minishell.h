/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 00:18:39 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/16 19:42:12 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>
# include <errno.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include "libft.h"

//	====================		MACROS      		====================

# define PROMPT "minishell$ "
# define PROMPT_SIZE 11

//	====================		STRUCTS      		====================

typedef struct s_minishell
{
	char	**envp;
	char	*input;
	char	**tokens;
	char	*dir;
}	t_minishell;


//	====================		MINISHELL.C      		====================
void	ft_loop(t_minishell *minishell);
void	ft_token_handler(t_minishell *minishell);

//	====================		SPLIT_TOKEN.C      		====================

//	====================		INPUT_VALIDATOR.C      		====================

//	====================		DIRECTORY.C      		====================
void	ft_get_dir(t_minishell *minishell);
#endif
