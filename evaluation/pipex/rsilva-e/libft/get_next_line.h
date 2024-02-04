/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsilva-e < rsilva-e@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:59:17 by fernacar          #+#    #+#             */
/*   Updated: 2023/10/21 17:04:27 by rsilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ftstrlen1(char *s);
char	*ft_strchr1(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*ft_substr1(char *s, int start, int len);
void	*ftcalloc1(size_t nmemb, size_t size);
char	*get_next_line(int fd);

#endif
