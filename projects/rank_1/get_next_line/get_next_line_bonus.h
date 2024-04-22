/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:40:43 by txisto-d          #+#    #+#             */
/*   Updated: 2023/10/23 20:09:57 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_getting(int fd, char *line);
char	*ft_cut(char *line);
char	*ft_update(char *line);
size_t	ft_strlen(char *str);
size_t	ft_linelen(char *str);
char	*ft_strjoin_nl(char *s1, char *s2);
int		ft_eol(char *str);
char	*ft_strncpy(char *dest, char *src, size_t len);

#endif