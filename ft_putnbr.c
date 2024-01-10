/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:59:54 by oait-laa          #+#    #+#             */
/*   Updated: 2023/12/23 17:29:51 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long n, int *i, int *err)
{
	char	c;

	if (n < 0)
	{
		n = -n;
		ft_putchar('-', i, err);
		ft_putnbr(n, i, err);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, i, err);
		ft_putnbr(n % 10, i, err);
	}
	else
	{
		c = n + 48;
		ft_putchar(c, i, err);
	}
}
