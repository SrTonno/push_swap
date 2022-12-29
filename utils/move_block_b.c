/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_block_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:50:34 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/29 18:33:16 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static t_order	*move_to_top_a(t_order *list_a, int min, int max, int mode)
{
	int	i;

	i = 0;
	list_a = find_first_list(list_a);
	while (i == 0)
	{
		if (mode == 0)
		{
			list_a = ft_ra (list_a);
			//ft_printf("a");
		}
		else
			list_a = ft_rra (list_a);
		list_a = find_first_list(list_a);
		if (min <= list_a->index && max >= list_a->index)
			i = 1;
	}
	return (list_a);
}

static int	search_top_or_under(t_order *list, int min, int max)
{
	int	top;
	int	under;
	int	len;

	list = find_first_list(list);
	len = ft_struclen(list);
	top = 0;
	under = 0;
	while (len > top)
	{
		if (min <= list->index && max >= list->index)
			break;
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

t_order	*move_block_b(t_order *list_a, t_order *list_b, int min, int max)
{
	int		check;
	int		count;
	int		total;
	t_order	*aux;

	count = 0;
	total = (max - min) + 1;
	while (total > count++)
	{
		check = search_top_or_under(list_a, min, max);
		list_a = move_to_top_a(list_a, min, max, check);
		//ft_printf("$a$%d/%d\n", list_a->number, list_a->index);
		list_a = list_a->next;
		ft_pb(list_a, list_b);
		if (count == 1 && ft_struclen(list_b) < 2)
		{
			aux = list_b;
			free (aux);
			list_b = list_b->back;
			list_b->next = NULL;
			//ft_printf("\n-----------\n");
		}
		else
			list_b = list_b->back;
		if (count != 1)
			list_b = psorder(list_b);
		//ft_printf("$b$%d/%d\n", list_b->number, list_b->index);
	}
	return (list_a);
}
