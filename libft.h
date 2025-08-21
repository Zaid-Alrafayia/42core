/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 00:06:37 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/22 01:27:23 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H

# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
void	*ft_memset(char *arr, char letter, size_t num);
void	*ft_memmove(char *dest, char *src, size_t n);
void	*ft_memcpy(char *dest, char *src);
int		ft_isprint(int num);
int		ft_isdigit(char letter);
int		ft_isascii(int num);
int		ft_isalpha(char letter);
int		ft_isalnum(char letter);
void	ft_bzero(char *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strnstr(const char *big, const char *small, size_t len);
int		ft_atoi(const char *str);
#endif // !LIBFT_H
