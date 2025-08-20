/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaalrafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 00:06:37 by zaalrafa          #+#    #+#             */
/*   Updated: 2025/08/21 00:19:44 by zaalrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int		ft_strlen(char *str);
char	ft_strlcpy(char *dest, char *src, int n);
void	ft_memset(char *arr, char letter, int num);
void	*ft_memmove(char *dest, char *src, int n);
void	*ft_memcpy(char *dest, char *src);
int		ft_isprint(int num);
int		ft_isdigit(char letter);
int		ft_isascii(int num);
int		ft_isalpha(char letter);
int		ft_isalnum(char letter);
void	ft_bzero(char *src, int n);
