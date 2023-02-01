/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:14:04 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/01 16:17:09 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_doble(t_print *mob)
{
	if (mob->next == NULL)
		return (0);
	if (mob->id + mob->next->id == 0)
		return (1);
	return (0);
}
static int	types_mob(t_print *mob)
{
	if (mob->id == 1)
		ft_printf("pa\n");
	else if (mob->id == -1)
		ft_printf("pb\n");
	else if	(check_doble(mob) == 1 && (mob->id == 2 || mob->id == -2))
		return (ft_printf("rrr\n"));
	else if (mob->id == 2)
		ft_printf("rra\n");
	else if (mob->id == -2)
		ft_printf("rrb\n");
	else if	(check_doble(mob) == 1 && (mob->id == 3 || mob->id == -3))
		return (ft_printf("rr\n"));
	else if (mob->id == 3)
		ft_printf("ra\n");
	else if (mob->id == -3)
		ft_printf("rb\n");
	else if	(check_doble(mob) == 1 && (mob->id == 4 || mob->id == -4))
		return (ft_printf("ss\n"));
	else if (mob->id == 4)
		ft_printf("sa\n");
	else if (mob->id == -4)
		ft_printf("sb\n");
	return (0);
}

static int	len_print(t_print *mob)
{
	int	count;

	count = 0;
	while (mob->next != NULL)
	{
		mob = mob->next;
		count++;
	}
	return (count);
}

void	print_list(t_print *mob)
{
	int	skip;
	int	count;
	int	i;

	i = 0;
	count = len_print(mob);
	mob = mob->next;
	while (i < count)
	{
		skip = types_mob(mob);
		if (skip > 0)
		{
			mob = mob->next;
			i++;
			if (mob->next == NULL)
				return ;
		}
		mob = mob->next;
		i++;
	}
}
