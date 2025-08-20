/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 00:06:37 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/21 00:50:53 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H

# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
size_t	ft_strlcpy(char *dest, char *src, size_t n);
void	*ft_memset(char *arr, char letter, size_t num);
void	*ft_memmove(char *dest, char *src, size_t n);
void	*ft_memcpy(char *dest, char *src);
int		ft_isprint(int num);
int		ft_isdigit(char letter);
int		ft_isascii(int num);
int		ft_isalpha(char letter);
int		ft_isalnum(char letter);
void	ft_bzero(char *src, size_t n);

#endif // !LIBFT_H
