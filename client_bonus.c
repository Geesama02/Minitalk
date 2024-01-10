/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:56:22 by oait-laa          #+#    #+#             */
/*   Updated: 2024/01/09 11:37:24 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printf_bits(unsigned char octet)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * 9);
	if (!str)
		exit(1);
	i = 0;
	while (i < 8)
	{
		if (octet & (1 << i))
			str[7 - i] = '1';
		else
			str[7 - i] = '0';
		i++;
	}
	str[8] = '\0';
	return (str);
}

void	send_char(unsigned char c, int x)
{
	int		i;
	char	*str;

	i = 0;
	str = printf_bits(c);
	while (i < 8)
	{
		if (str[i] == '1')
		{
			if (kill(x, SIGUSR1) != 0)
				exit(1);
		}
		else
		{
			if (kill(x, SIGUSR2) != 0)
				exit(1);
		}
		i++;
		usleep(200);
	}
	free(str);
}

void	split_to_bits(char *str, int x)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(str[i], x);
		i++;
	}
	send_char(str[i], x);
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message Received\n");
}

int	main(int argc, char *argv[])
{
	int					x;
	struct sigaction	reply;

	if (argc != 3)
	{
		ft_printf("Invalid Arguments Number\n");
		return (1);
	}
	if (!ft_isdigit(argv[1]) || ft_atoi(argv[1]) <= 1)
	{
		ft_printf("Invalid PID\n");
		return (0);
	}
	reply.sa_handler = &handler;
	reply.sa_flags = SA_RESTART;
	sigemptyset(&reply.sa_mask);
	sigaction(SIGUSR1, &reply, NULL);
	x = ft_atoi(argv[1]);
	split_to_bits(argv[2], x);
	return (0);
}
