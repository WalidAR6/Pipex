/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waraissi <waraissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:04:17 by waraissi          #+#    #+#             */
/*   Updated: 2023/01/06 15:03:55 by waraissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include<fcntl.h>
# include<stdlib.h>
# include<string.h>
# include<stdio.h>
# include<unistd.h>
# include<ctype.h>
# include<stdarg.h>

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *str, const char *look, size_t n);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	*ft_memchr(const void *str, int c, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
/*************************BONUS PART****************************/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*************************GET NEXT LINE****************************/

int		is_newline(char *str);
char	*ft_strjoin_free(char *s1, char *s2);
int		get_index(char	*str);
char	*before_newline(char *str);
char	*after_newline(char *str);
char	*get_next_line(int fd);

/*************************GET NEXT LINE****************************/

void	ft_putchar(int fd, char c, int *res);
void	ft_putstr(int fd, char *s, int *res);
void	ft_putnbr(int fd, int n, int *res);
void	ft_putnbr_unsigned(int fd, unsigned int nbr, int *res);
void	ft_putnbr_base(int fd, unsigned long long nbr, int *res);
void	ft_putnbr_base_lower(int fd, unsigned int nbr, int *res);
void	ft_putnbr_base_upper(int fd, unsigned int nbr, int *res);
int		ft_printf(int fd, const char *str, ...);

/*************************FT_PRINTF_FD****************************/

void	ft_putchar(int fd, char c, int *res);
void	ft_putstr(int fd, char *s, int *res);
void	ft_putnbr(int fd, int n, int *res);
void	ft_putnbr_unsigned(int fd, unsigned int nbr, int *res);
void	ft_putnbr_base(int fd, unsigned long long nbr, int *res);
void	ft_putnbr_base_lower(int fd, unsigned int nbr, int *res);
void	ft_putnbr_base_upper(int fd, unsigned int nbr, int *res);
int		ft_printf(int fd, const char *str, ...);

#endif
