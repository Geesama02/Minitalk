/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-laa <oait-laa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:56:43 by oait-laa          #+#    #+#             */
/*   Updated: 2024/01/09 11:44:41 by oait-laa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_buffer(int *buffer, int *i)
{
	int	j;

	j = 0;
	while (*i >= 0)
	{
		write(1, &buffer[j], 1);
		j++;
		(*i)--;
	}
	*i = 0;
}

void	if_unicode(int *buffer, int *i, int *check, int result)
{
	if (result >= 128 && result < 192)
	{
		(*check)--;
		(*i)++;
	}
	else if (result >= 192 && result < 224)
		*check = 1;
	else if (result >= 224 && result < 240)
		*check = 2;
	else if (result >= 240)
		*check = 3;
	else
		*check = 0;
	buffer[*i] = result;
}

void	bits_to_char(char *bits, siginfo_t *info)
{
	int			result;
	static int	check;
	static int	i;
	static int	buffer[4];
	static int	pid;

	result = 0;
	if (pid != info->si_pid && info->si_pid != 0)
	{
		i = 0;
		check = 0;
		pid = info->si_pid;
	}
	while (*bits)
	{
		result *= 2;
		if (*bits++ == '1')
			result += 1;
	}
	if (result == '\0')
		if (kill(info->si_pid, SIGUSR1) != 0)
			exit(1);
	if_unicode(buffer, &i, &check, result);
	if (check == 0)
		write_buffer(buffer, &i);
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
		bits_to_char(character, info);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	action.sa_sigaction = handler;
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
