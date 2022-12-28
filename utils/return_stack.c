/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:17:05 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/28 12:41:35 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_to_top(t_order *list_b, int min, int max)
{
	int	count;

	count = 0;

	list_b = find_first_list(list_b);
	while (list_b->next != NULL)
	{
		count++;
		if (max == list_b->number || min == list_b->number)
			break ;
		list_b = list_b->next;
	}
	//ft_printf("top(%d-index=%d)", list_b->number, list_b->back);
	return (count);
}

static int	find_to_under(t_order *list_b, int min, int max)
{
	int	count;

	count = 0;
	list_b = find_end_list(list_b);
	while (list_b->back != NULL)
	{
		count++;
		if (max == list_b->number || min == list_b->number)
			break ;
		list_b = list_b->back;
	}
	//ft_printf("under(%d-index=%d)", list_b->number, list_b->back);
	return (count + 1);
}

void return_to_a(t_order *list_a, t_order *list_b, int count)
{
	int	max;
	int	min;
	int	i;

	i = 0;
	while (count > i++)
	{

		max = find_max_value(list_b);
		min = find_min_value(list_b);
		list_b = find_first_list(list_b);
		if (find_to_top(list_b, min, max)
			> find_to_under(list_b, min, max)) // mover desde abajo
		{
			while (max != list_b->number && min != list_b->number)
				list_b = ft_rrb(list_b);
			list_b = list_b->next;
			ft_pa(list_b, list_a);
		}
		else if (list_b->next == NULL)
			ft_pa(list_b, list_a);
		else//mover desde arriba
		{
			while (max != list_b->number && min != list_b->number)
				list_b = ft_rb(list_b);
			list_b = list_b->next;
			ft_pa(list_b, list_a);
		}
		list_a = find_first_list(list_a);
		if (min == list_a->number)
			list_a = ft_ra(list_a);
	}
}
