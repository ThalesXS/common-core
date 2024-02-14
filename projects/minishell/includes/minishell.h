/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 00:18:39 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/14 00:32:09 by txisto-d         ###   ########.fr       */
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

#endif
