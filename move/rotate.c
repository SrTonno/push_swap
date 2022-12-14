/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:53:28 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/14 12:19:26 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_order	*ra_rb(t_order *list)
{
	t_order	*find;
	t_order	*tmp;

	find = find_end_list(list);
	tmp = list->next;
	find->next = list;
	list->next = NULL;
	return (tmp);
}

void	rotate(t_order *list_a, t_order *list_b)
{
	list_a = ra_rb(list_a);
	list_b = ra_rb(list_b);
}

t_order	*rra_rrb(t_order *list)
{
	t_order	*find;
	t_order	*aux;

	aux = list;
	while (aux->next->next)
	{
		aux = aux->next;
	}
	find = find_end_list(list);
	find->next = list;
	aux->next = NULL;
	return (find);
}

void	reverse(t_order *list_a, t_order *list_b)
{
	list_a = rra_rrb(list_a);
	list_b = rra_rrb(list_b);
}
