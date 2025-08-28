/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:32:41 by thblack-          #+#    #+#             */
/*   Updated: 2025/07/25 14:12:27 by thblack-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// ASCII

// Checks if input int 'c' is alphabetic character in ascii
int		ft_isalpha(int c);
// Checks if input int 'c' is numeric character in ascii
int		ft_isdigit(int c);
// Checks if input int 'c' is numeric character or sign in ascii
int		ft_isnum(int c);
// Checks if input int 'c' is alphanumeric character in ascii
int		ft_isalnum(int c);
// Checks if input int 'c' is valid character in ascii
int		ft_isascii(int c);
// Checks if input int 'c' is printable character in ascii
int		ft_isprint(int c);
// Checks if input int 'c' is whitespace character in ascii
int		ft_isspace(int c);
// If input int 'c' is lowercase ascii then it converts to uppercase
int		ft_toupper(int c);
// If input int 'c' is uppercase ascii then it converts to lowercase
int		ft_tolower(int c);

// GNL
char	*get_next_line(int fd);

// LISTS
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// MEMORY
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

// NUMBERS
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		ft_digitcount(unsigned int n, unsigned int base);

// PRINTING
int		ft_putchar(char c);
int		ft_putstr(const char *s);
int		ft_putnbr(int n);
int		ft_putuint(unsigned int n);
int		ft_puthex(unsigned long nbr, const char *hex);
int		ft_putptr(va_list args);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf(const char *format, ...);

// STRINGS
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

#endif
