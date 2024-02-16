/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 05:12:47 by txisto-d          #+#    #+#             */
/*   Updated: 2024/02/15 22:47:52 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

/**
 * @brief Converts a string to it's INT form.
 * @param nptr The string to be converted.
 * @return The integer form of the string.
*/
int		ft_atoi(const char *nptr);

/**
 * @brief Turn n bytes into 0.
 * @param s The pointer to the memory to be set to 0.
 * @param n The number of bytes to be set to 0.
*/
void	ft_bzero(void *s, size_t n);

/**
 * @brief Allocates memory for an array of nmemb elements of size bytes each,
 *  sets all it's bytes to 0 and returns a pointer to the allocated memory.
 * @param nmemb The number of elements to be allocated.
 * @param size The size of each element.
 * @return A pointer to the allocated memory.
*/
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Checks if a character is alphanumeric.
 * @param c The character to be checked.
 * @return 1 if the character is alphanumeric, 0 otherwise.
*/
int		ft_isalnum(int c);

/**
 * @brief Checks if a character is alphabetic.
 * @param c The character to be checked.
 * @return 1 if the character is alphabetic, 0 otherwise.
*/
int		ft_isalpha(int c);

/**
 * @brief Checks if a character is an ASCII character.
 * @param c The character to be checked.
 * @return 1 if the character is an ASCII character, 0 otherwise.
*/
int		ft_isascii(int c);

/**
 * @brief Checks if a character is a digit.
 * @param c The character to be checked.
 * @return 1 if the character is a digit, 0 otherwise.
*/
int		ft_isdigit(int c);

/**
 * @brief Checks if a character is printable.
 * @param c The character to be checked.
 * @return 1 if the character is printable, 0 otherwise.
*/
int		ft_isprint(int c);

/**
 * @brief Allocates memory for a new string and write
 *  a given INT number into it.
 * @param n The integer number to be converted.
 * @return A pointer to the new string.
*/
char	*ft_itoa(int n);

/**
 * @brief Search for a BYTE inside the given address, loop up to n bytes.
 * @param s The address to be searched on.
 * @param c The byte to be searched.
 * @param n The number of bytes to be compared.
 * @return A pointer to the first ocurrence of the byte.
*/
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compare two memory blocks.
 * @param s1 The first memory block.
 * @param s2 The second memory block.
 * @param n The number of bytes to be compared.
 * @return 0 if the memory blocks are equal, a positive number if s1 
 * is greater than s2, a negative number if s1 is less than s2.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Copy n bytes from src to dest, memory may overlap,
 *  so it's advised to use "ft_memmove()".
 * @param dest The destination address.
 * @param src The source address.
 * @param n The number of bytes to be copied.
 * @return A pointer to the destination address.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copy n bytes from src to dest, even if the memory blocks overlap.
 * @param dest The destination address.
 * @param src The source address.
 * @param n The number of bytes to be copied.
 * @return A pointer to the destination address.
*/
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Set n bytes of a memory block to a given value.
 * @param s The address of the memory block to be set.
 * @param c The value to be set.
 * @param n The number of bytes to be set.
 * @return A pointer to the memory block.
*/
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief Write a char inside an especific fd.
 * @param c The char to be written.
 * @param fd The file descriptor.
*/
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Write a string and a "\\n" inside an especific fd.
 * @param s The string to be written
 * @param fd The file descriptor.
*/
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Write a INT number inside an especific fd.
 * @param n The integer to be written.
 * @param fd The file descriptor.
*/
void	ft_putnbr_fd(int n, int fd);

/**
 * @brief Write a string inside an especific fd.
 * @param s The string to be written.
 * @param fd The file descriptor.
*/
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Split a string into an array of strings using a given character
 *  as a delimiter.
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return An NULL terminated array of strings.
*/
char	**ft_split(char const *s, char c);

/**
 * @brief Search for a CHAR inside a string.
 * @param s The string to be searched on.
 * @param c The character to be searched.
 * @return A pointer to the first ocurrence of the character.
*/
char	*ft_strchr(const char *s, int c);

/**
 * @brief Duplicate a string by allocating memory and copying the original
 *  string into it.
 * @param s The string to be duplicated.
 * @return A pointer to the new string.
*/
char	*ft_strdup(const char *s);

/**
 * @brief Join two strings into a new one by allocating memory.
 * @param s1 The first string.
 * @param s2 The second string.
 * @return A pointer to the new string.
*/
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Concatenate two strings.
 * @param dst The destination string.
 * @param src The source string.
 * @param size The size of the destination string.
 * @return The length of the concatenated string.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Copy a string into another.
 * @param dst The destination string.
 * @param src The source string.
 * @param size The size of the destination string.
 * @return The length of the source string.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Get the length of a string.
 * @param s The string to be measured.
 * @return The length of the string.
*/
size_t	ft_strlen(const char *s);

/**
 * @brief Create a new string by applying a function to each character
 *  of a given string.
 * @param s The string to be mapped.
 * @param f The function to be applied, it takes the index of the
 *  character and the character itself as arguments.
 * @return A pointer to the new string.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Compare two strings up to n chars.
 * @param s1 The first string.
 * @param s2 The second string.
 * @return 0 if the strings are equal up to n chars, a positive number
 *  if s1 is greater than s2, a negative number if s1 is less than s2.
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Search for a string inside another.
 * @param big The string to be searched on.
 * @param little The string to be searched.
 * @return A pointer to the first ocurrence of the string.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Reverse search for a CHAR inside a string.
 * @param s The string to be searched on.
 * @param c The character to be searched.
 * @return A pointer to the last ocurrence of the character in the string.
*/
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Change the string by applying a function to each character of it.
 * @param s The string to be changed.
 * @param f The function to be applied, it takes the character position
 *  and address as arguments.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @brief Removes the leading and trailing characters specified in the set
 *  from the string and creates a string with the remaining characters 
 * by allocating memory.
 * @param s1 The string to be trimmed.
 * @param set The set of characters to be removed.
 * @return A pointer to the new string.
*/
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Create a substring from a string by allocating memory.
 * @param s The string to be substringed.
 * @param start The start index of the substring.
 * @param len The length of the substring.
 * @return A pointer to the new string.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Convert a CHAR to lowercase.
 * @param c The character to be converted.
 * @return The lowercase character.
*/
int		ft_tolower(int c);

/**
 * @brief Convert a CHAR to uppercase.
 * @param c The character to be converted.
 * @return The uppercase character.
*/
int		ft_toupper(int c);

//	========================			BONUS			========================

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

/**
 * @brief Add a new element to the end of the list.
 * @param lst The address of the first element of the list.
 * @param new The address of the new element to be added.
*/
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Add a new element to the beginning of the list.
 * @param lst The address of the first element of the list.
 * @param new The address of the new element to be added.
*/
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Clear the list by deleting all it's elements.
 * @param lst The address of the first element of the list.
 * @param del The function to free the content.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Delete the node at the given position.
 * @param lst The address of the node to be deleted.
 * @param del The function to free the content.
 * @return A pointer to the new element.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Apply a function to each element of the list.
 * @param lst The address of the first element of the list.
 * @param f The function to be applied.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Create a new list element by allocating memory and
 *  copying the content of the original element into it.
 * @param lst The address of the first element of the list.
 * @param f The function to be applied.
 * @param del A delete function to be applied to each element in case of error.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Return a pointer to the last element of the list.
 * @param lst The address of the first element of the list.
 * @return A pointer to the last element of the list.
*/
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Create a new list element by allocating memory and
 *  copying the content of the original element into it.
 * @param content The content of the new element.
 * @return A pointer to the new element.
*/
t_list	*ft_lstnew(void *content);

/**
 * @brief Return the number of elements in the list.
 * @param lst The address of the first element of the list.
 * @return The number of elements in the list.
*/
int		ft_lstsize(t_list *lst);

//	========================			PRINTF			========================

typedef struct s_arg
{
	int		width;
	int		minus;
	int		precision;
	int		zero;
	int		plus;
	int		space;
	int		hash;
	int		dot;
	int		specifier;
}			t_arg;

typedef struct s_string
{
	size_t	len;
}			t_string;

/**
 * @brief A reimplementation of the printf function.
 * @param format The format string.
 * @param ... The arguments to be printed.
 * @return The number of characters printed.
*/
int		ft_printf(const char *format, ...);
void	ft_print_c(t_arg *arg, t_string *string, va_list lst);
void	ft_print_d(t_arg *arg, t_string *string, va_list lst);
void	ft_print_p(t_arg *arg, t_string *string, va_list lst);
void	ft_print_s(t_arg *arg, t_string *string, va_list lst);
void	ft_print_u(t_arg *arg, t_string *string, va_list lst);
void	ft_print_x(t_arg *arg, t_string *string, va_list lst);
void	ft_print_xx(t_arg *arg, t_string *string, va_list lst);
int		ft_converter(const char *format, va_list lst, t_string *string);
int		ft_printlen(const char *str);
int		ft_flaglen(const char *str);
void	ft_printchar(char c, t_string *string);
void	ft_printstr(const char *s, t_string *string);
void	ft_printstr_ltda(const char *s, t_string *string);
char	*ft_ptoa(unsigned long n);
char	*ft_utoa(unsigned int n);
char	*ft_xtoa(unsigned int n);
char	*ft_xxtoa(unsigned int n);
int		ft_specif(char specifier, char *flags, va_list lst, t_string *string);

//	========================		GET_NEXT_LINE		========================

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

/**
 * @brief Read a line from a file descriptor.
 * @param fd The file descriptor.
 * @return A pointer to the line read (Memory must be freed).
*/
char	*get_next_line(int fd);
char	*ft_getting(int fd, char *line);
char	*ft_cut(char *line);
char	*ft_update(char *line);
size_t	ft_linelen(char *str);
char	*ft_strjoin_nl(char *s1, char *s2);
int		ft_eol(char *str);
char	*ft_strncpy(char *dest, char *src, size_t len);

//	========================		MY_EXTRAS			========================

/**
 * @brief Return the length of a line without counting the "\\n" character.
 * @param str The string to be measured.
 * @return The length of the line.
*/
size_t	ft_line_no_n(char *str);

#endif
