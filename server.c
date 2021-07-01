/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:49:40 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/07/01 12:51:29 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

static void	ft_print_pid(void)
{
	char	*tmp_pid;
	pid_t	pid;

	pid = getpid();
	tmp_pid = ft_itoa((int)pid);
	write(1, "SERVER_PID = ", 13);
	write(1, tmp_pid, ft_strlen(tmp_pid));
	write(1, "\n", 1);
}

static void	bin_to_char(char *bin)
{
	char	*start;
	int		total;

	total = 0;
	start = bin;
	while (*start)
	{
		total *= 2;
		if (*start++ == '1')
			total += 1;
	}
	write(1, &total, 1);
}

static void	ft_get_msg(int signum)
{
	static char	bit[9];
	int			i;
	int			binary_nb;

	binary_nb = 0;
	i = 0;
	while (bit[i])
		i++;
	if (signum == SIGUSR1)
		bit[i] = '1';
	else if (signum == SIGUSR2)
		bit[i] = '0';
	bit[i + 1] = '\0';
	if (i == 7)
	{
		bin_to_char(bit);
		bit[0] = '\0';
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	signal(SIGUSR1, ft_get_msg);
	signal(SIGUSR2, ft_get_msg);
	ft_print_pid();
	while (1)
		pause();
	return (0);
}
