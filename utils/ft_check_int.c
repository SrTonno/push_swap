/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:37:23 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/06 16:42:22 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	quitar_espacios(const char *str)
{
	long	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	return (i);
}

static long	no_numero(const char *str, long i)
{
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

static unsigned long	num_final(const char *str, long i, long z)
{
	unsigned long	num;
	unsigned long	sub;

	sub = 1;
	num = 0;
	z--;
	while (i <= z)
	{
		num = num + ((str[z] - '0') * sub);
		sub = sub * 10;
		z--;
	}
	return (num);
}

int	ft_check_int(const char *str)
{
	unsigned long	i;
	long			signo;
	unsigned long	final;

	i = quitar_espacios(str);
	signo = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
				signo++;
	if (ft_isdigit(str[i]) == 0)
		return (0);
	if (str[i] < 48 || str[i] > 57)
		return (0);
	final = num_final(str, i, no_numero(str, i));
	if ((final > INT_MAX && signo == 0) || (final > INT_MAX && signo == 1))
		return (-1);
	else
		return (1);
}
