/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:07:53 by txisto-d          #+#    #+#             */
/*   Updated: 2023/10/21 15:43:45 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
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