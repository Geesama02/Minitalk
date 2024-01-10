/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:00:46 by oait-laa          #+#    #+#             */
/*   Updated: 2023/11/13 20:06:19 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lower_hex(unsigned int n, int *i, int *err)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n / 16 > 0)
	{
		lower_hex(n / 16, i, err);
	}
	ft_putchar(hex[n % 16], i, err);
}
