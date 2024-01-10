/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upper_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:01:17 by oait-laa          #+#    #+#             */
/*   Updated: 2023/11/13 20:06:47 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	upper_hex(unsigned int n, int *i, int *err)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (n / 16 > 0)
	{
		upper_hex(n / 16, i, err);
	}
	ft_putchar(hex[n % 16], i, err);
}
