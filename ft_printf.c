/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:55:59 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/23 17:30:05 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_var(char c, va_list args, int *err)
{
	int	i;

	i = 0;
	if (c == 'c')
		ft_putchar(va_arg(args, int), &i, err);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), &i, err);
	else if (c == 'p')
		ft_print_mem(va_arg(args, void *), &i, err);
	else if (c == 'i')
		ft_putnbr(va_arg(args, int), &i, err);
	else if (c == 'd')
		ft_putnbr(va_arg(args, int), &i, err);
	else if (c == 'u')
		u_print(va_arg(args, int), &i, err);
	else if (c == 'x')
		lower_hex(va_arg(args, int), &i, err);
	else if (c == 'X')
		upper_hex(va_arg(args, int), &i, err);
	else if (c == '%')
		ft_putchar('%', &i, err);
	else
		ft_putchar(c, &i, err);
	return (i - 2);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		err;
	int		i;
	int		j;

	err = 0;
	i = 0;
	j = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
			ft_putchar(format[i], &i, &err);
		if (format[i])
		{
			i++;
			j += write_var(format[i++], args, &err);
		}
	}
	va_end(args);
	if (err == -1)
		return (-1);
	return (i + j);
}
