/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:59:04 by oait-laa          #+#    #+#             */
/*   Updated: 2023/11/13 20:05:58 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_mem(void *ptr, int *j, int *err)
{
	char			*hex;
	char			tmp[17];
	int				i;
	unsigned long	address;

	address = (unsigned long)ptr;
	hex = "0123456789abcdef";
	i = 0;
	if (address == 0)
	{
		ft_putstr("0x0", j, err);
		return ;
	}
	while (address != 0)
	{
		tmp[i++] = hex[address % 16];
		address /= 16;
	}
	ft_putstr("0x", j, err);
	while (i > 0)
	{
		i--;
		ft_putchar(tmp[i], j, err);
	}
}
