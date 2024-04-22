# Libft

## Overview

Libft is the inaugural project of the Common Core curriculum, designed to create a robust and tested library of essential C functions. Rigorous testing is essential as this library will serve as a foundation for future projects. The code is intended to be correct, concise, and easily understandable for maintenance and expansion.

## Roadmap

### Part 1 - Libc functions

Function | Description | Status
--- | --- | ---
`ft_isdigit` | Check if the character is a digit | ✅
`ft_isalnum` | Check if the character is alphanumeric | ✅
`ft_isascii` | Verify if the character belongs to the ASCII table | ✅
`ft_isprint` | Check if the character is printable | ✅
`ft_strlen` | Return the length of a string | ✅
`ft_memset` | Fill a memory area with a specific byte | ✅
`ft_bzero` | Set the first n bytes of a memory area to zero | ✅
`ft_memcpy` | Copy a memory area to another | ✅
`ft_memmove` | Move a memory area to another | ✅
`ft_strlcpy` | Copy a string, ensuring a maximum size | ✅
`ft_strlcat` | Concatenate two strings, ensuring a maximum size | ✅
`ft_toupper` | Convert a character to uppercase | ✅
`ft_tolower` | Convert a character to lowercase | ✅
`ft_strchr` | Locate the first occurrence of a character in a string | ✅
`ft_strrchr` | Locate the last occurrence of a character in a string | ✅
`ft_strncmp` | Compare the first n characters of two strings | ✅
`ft_memchr` | Locate the first occurrence of a byte in a memory area | ✅
`ft_memcmp` | Compare two memory areas | ✅
`ft_strnstr` | Locate a substring in a string with a maximum length | ✅
`ft_atoi` | Convert a string to an integer | ✅
`ft_calloc` | Allocate a memory area and initialize it with zero | ✅
`ft_strdup` | Duplicate an existing string | ✅

### Part 2 - Additional functions

Function | Description | Status
--- | --- | ---
`ft_substr` | Return a specific part of a string | ✅
`ft_strjoin` | Return the concatenation of two strings | ✅
`ft_strtrim` | Remove specific characters from the beginning and end of a string | ✅
`ft_split` | Return a `null-terminated` array of strings separated by a specified separator | ✅
`ft_itoa` | Return a string that is the representation of a number | ✅
`ft_strmapi` | Return a string where a function is executed for each character of a string | ✅
`ft_striteri` | Apply a function to each character of a string | ✅
`ft_putchar_fd` | Output a character to the specified file descriptor | ✅
`ft_putstr_fd` | Output a string to the specified file descriptor | ✅
`ft_putendl_fd` | Output a string terminated in `\n` to the specified file descriptor | ✅
`ft_putnbr_fd` | Output a number to the specified file descriptor | ✅

### Bonus part

Function | Description | Status
--- | --- | ---
`ft_lstnew` | Return a new list node | ✅
`ft_lstadd_front` | Adds a node at the beginning of the list | ✅
`ft_lstsize` | Returns the number of nodes in the list | ✅
`ft_lstlast` | Returns the last node of the list | ✅
`ft_lstadd_back` | Adds a node at the end of the list | ✅
`ft_lstdelone` | Frees a node content by aplying a function to it | ✅
`ft_lstclear` | Deletes and frees the given node and every sucessor of that node | ✅
`ft_lstiter` | Apply a function to each node of a list | ✅
`ft_lstmap` | Return a new list where a function is executed for each node of a list | ✅

---

**Note:**
- ✅ for implemented functions
- 🚧 for functions in progress
