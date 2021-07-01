/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:44:48 by mlecuyer          #+#    #+#             */
/*   Updated: 2021/07/01 13:06:18 by mlecuyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

static unsigned char	*ft_char_to_bin(char c)
{
	unsigned char	*bin;
	int				i;
	int				j;

	i = 7;
	j = 0;
	bin = (unsigned char *)malloc(sizeof(char) * 9);
	if (!bin)
		return (NULL);
	while (i >= 0 && j < 8)
	{
		if ((c & (1 << i)))
			bin[j] = '1';
		else
			bin[j] = '0';
		i--;
		j++;
	}
	bin[8] = '\0';
	return (bin);
}

static void	send_signal(pid_t pid, char c)
{
	if (c == '0')
		kill(pid, SIGUSR2);
	if (c == '1')
		kill(pid, SIGUSR1);
	usleep(150);
}

static int	ft_check_args(int ac, char *av)
{
	int	i;

	i = 0;
	if (ac != 3)
	{
		write(1, "Number of arguments is invalid\n", 32);
		return (-1);
	}
	while (av[i])
	{
		if (ft_isdigit(av[i]) == 0)
		{
			write(1, "PID is invalid\n", 15);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int				i;
	int				j;
	unsigned char	*bin;

	if (ft_check_args(argc, argv[1]) == -1)
		return (-1);
	i = 0;
	while (argv[2][i])
	{
		bin = ft_char_to_bin(argv[2][i]);
		j = 0;
		while (bin[j])
		{
			send_signal(ft_atoi(argv[1]), bin[j]);
			j++;
		}
		i++;
	}
	free(bin);
	return (0);
}
