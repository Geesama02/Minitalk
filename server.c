/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:55:37 by oait-laa          #+#    #+#             */
/*   Updated: 2024/01/09 11:42:35 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	bits_to_char(char *bits)
{
	char	result;

	result = 0;
	while (*bits)
	{
		result *= 2;
		if (*bits++ == '1')
			result += 1;
	}
	write(1, &result, 1);
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	character[9];
	static int	i;
	static int	pid;

	(void)ucontext;
	if (pid != info->si_pid && info->si_pid != 0)
	{
		i = 0;
		pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		character[i++] = '1';
	else if (sig == SIGUSR2)
		character[i++] = '0';
	if (i == 8)
	{
		character[i] = '\0';
		i = 0;
		bits_to_char(character);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	action.sa_sigaction = &handler;
	action.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &action, NULL) == -1)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (sigaction(SIGUSR2, &action, NULL) == -1)
	{
		ft_printf("Error\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
