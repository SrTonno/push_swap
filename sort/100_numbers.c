/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:34:36 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/02 12:57:55 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	max_index(t_order *list)
{
	int	len;
	int	max;
	int	i;

	i = 0;
	list = find_first_list(list);
	len = ft_struclen(list);
	max = list->index;
	list = list->next;
	while (len > i++)
	{
		if (max < list->index)
			max = list->index;
		list = list->next;
	}
	return (max);

}

t_order	*hundred_number(t_order *list_a, t_print *mob)
{
	t_order *list_b;
	int	limits[2];
	int	top;
	int	i;
	int	interval;

	top = max_index(list_a);
	interval = (top / 6) + 1;
	limits[0] = 0;
	limits[1] = limits[0] + interval;
	i = 0;
	list_a = find_first_list(list_a);
	list_b = ft_calloc(1, sizeof(t_order));
	while (6 > i++)
	{
		list_a = move_block_b(list_a, list_b, limits, mob);
		limits[0] = limits[1] + 1;
		limits[1] = limits[0] + interval;
		if (top - 5 <= limits[1])
			limits[1] = top - 5;
		list_b = find_first_list(list_b);
	}
	list_a = five_number(list_a, mob);
	total_return(list_b, list_a, top - 5, mob);
	list_a = find_first_list(list_a);
	return (list_a);
}
