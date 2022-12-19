/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_block_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:50:34 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/19 18:34:58 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static t_order	*move_to_top_a(t_order *list_a, int min, int max, int mode)
{
	list_a = find_first_list(list_a);
	while (min > list_a->index && max < list_a->index)
	{
		if (mode == 0)
			list_a =ft_ra (list_a);
		else
			list_a = ft_rra (list_a);
		list_a = find_first_list(list_a);
	}
	return (list_a);
}

static int	search_top_or_under(t_order *list, int min, int max)
{
	int	top;
	int	under;
	int	len;

	list = find_first_list(list);
	len = ft_struclen(list) + 1;
	top = 0;
	under = 0;
	while (len > top)
	{
		if (min <= list->index && max >= list->index)
			break;
		list = list->next;
		top++;
	}
	list = find_first_list(list);
	while (len > under)
	{
		if (min <= list->index && max >= list->index)
			break ;
		list = list->back;
		under++;
	}
	if (top <= under + 1)
		return (0);
	return (1);
}

t_order	*move_block_b(t_order *list_a, t_order *list_b, int min, int max)
{
	int	check;
	int	count;
	int	total;

	count = 0;
	total = max - min;
	while (total > count++)
	{
		check = search_top_or_under(list_a, 80, 100);
		list_a = move_to_top_a(list_a, 80, 100, check);
		list_a = list_a->next;
		ft_pb(list_a, list_b);
	}
	return (list_a);
}
