/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:08:58 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/02 17:13:30 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	mult_2(int num)
{
	int	mult;
	int	count;
	int	aux;

	count = 0;
	mult = 1;
	while (num > mult)
	{
		aux = mult;
		mult *= 2;
		count++;
	}
	return (count);
}

t_order	*push_zero(t_order *list_a, t_order *list_b, t_print *mob, int mult)
{
	int		count;
	int		max;
	t_order	*tmp;

	max = ft_struclen(list_a);
	count = 1;
	list_a = find_first_list(list_a);
	while (max + 1 >= count++)
	{
		if (list_a->index & mult)
			list_a = ft_ra(list_a, mob);
		else
		{
			tmp = list_a->next;
			ft_pb(list_a, list_b, mob);
			list_a = tmp;
		}
	}
	return (list_a);
}

static void	return_zero(t_order *list_a, t_order *list_b, t_print *mob)
{
	int		count;
	int		max;
	t_order	*tmp;

	list_b = find_first_list(list_b);
	max = ft_struclen(list_b);
	count = 0;
	list_a = find_first_list(list_a);
	while (max > count++)
	{
		if (list_b == NULL)
			break ;
		tmp = list_b->next;
		ft_pa(list_b, list_a, mob);
		list_b = tmp;
		list_a = find_first_list(list_a);
	}
}

void	radix(t_order *list_a, t_print *mob)
{
	t_order	*list_b;
	int		mult;
	int		max;
	int		count;

	mult = 1;
	count = 1;
	max = mult_2(ft_struclen(list_a) + 1);
	list_b = ft_calloc(1, sizeof(t_order));
	list_b->index = -2;
	while (max >= count)
	{
		list_a = push_zero(list_a, list_b, mob, mult);
		return_zero(list_a, list_b, mob);
		count++;
		mult *= 2;
	}
}
