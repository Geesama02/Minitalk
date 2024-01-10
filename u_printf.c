/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:00:17 by oait-laa          #+#    #+#             */
/*   Updated: 2024/01/02 12:28:22 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_print(unsigned int n, int *i, int *err)
{
	char	c;

	if (n < 0)
	{
		n = -n;
		ft_putchar('-', i, err);
		u_print(n, i, err);
	}
	else if (n > 9)
	{
		u_print(n / 10, i, err);
		u_print(n % 10, i, err);
	}
	else
	{
		c = n + 48;
		ft_putchar(c, i, err);
	}
}
