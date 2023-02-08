/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_block_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:50:34 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/08 12:27:23 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_order	*move_top_a(t_order *list_a, int limits[2], int mode, t_print *mob)
{
	int	i;

	i = 0;
	list_a = find_first_list(list_a);
	while (i == 0)
	{
		if (mode == 0)
			list_a = ft_ra (list_a, mob);
		else
			list_a = ft_rra (list_a, mob);
		list_a = find_first_list(list_a);
		if (limits[0] <= list_a->index && limits[1] >= list_a->index)
			i = 1;
	}
	return (list_a);
}

int	search_top_or_under(t_order *list, int min, int max, int len)
{
	int	top;
	int	under;

	list = find_first_list(list);
	len = ft_struclen(list);
	top = 0;
	under = 0;
	while (len > top)
	{
		if (min <= list->index && max >= list->index)
			break ;
		list = list->next;
		top++;
	}
	list = find_end_list(list);
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

static t_order	*delete_block_b(t_order *list_b)
{
	t_order	*aux;

	aux = list_b;
	list_b = list_b->back;
	free (aux);
	list_b->next = NULL;
	return (list_b);
}

t_order	*move_block_b(t_order *list_a, t_order *list_b, \
	int limits[2], t_print *mob)
{
	int		check;
	int		count;
	int		total;

	count = 0;
	total = (limits[1] - limits[0]) + 1;
	while (total > count++)
	{
		check = search_top_or_under(list_a, limits[0], limits[1], \
			ft_struclen(list_a));
		list_a = move_top_a(list_a, limits, check, mob);
		list_a = list_a->next;
		ft_pb(list_a, list_b, mob);
		if (count == 1 && ft_struclen(list_b) < 2)
			list_b = delete_block_b(list_b);
		else
			list_b = list_b->back;
		if (count != 1)
			list_b = psorder(list_b, limits[1], mob);
	}
	return (list_a);
}
