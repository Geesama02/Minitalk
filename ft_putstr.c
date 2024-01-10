/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:58:13 by oait-laa          #+#    #+#             */
/*   Updated: 2023/11/13 19:57:57 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *j, int *err)
{
	int	i;

	if (str == NULL)
	{
		ft_putstr("(null)", j, err);
		return ;
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], &i, err);
		(*j)++;
	}
}
