/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:02:06 by oait-laa          #+#    #+#             */
/*   Updated: 2024/01/09 11:32:32 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	upper_hex(unsigned int n, int *i, int *err);
void	lower_hex(unsigned int n, int *i, int *err);
void	ft_putstr(char *str, int *i, int *err);
void	ft_putnbr(long n, int *i, int *err);
void	ft_putchar(char c, int *i, int *err);
void	ft_print_mem(void *ptr, int *i, int *err);
void	u_print(unsigned int n, int *i, int *err);
int		write_var(char c, va_list args, int *err);
int		ft_printf(const char *format, ...);
int		ft_atoi(const char *str);
int		ft_isdigit(char *str);

#endif