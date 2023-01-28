/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:53:28 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/28 12:10:54 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_order	*rotate(t_order *list)
{
	t_order	*find;
	t_order	*tmp;

	find = find_end_list(list);
	list = find_first_list(list);
	tmp = list->next;
	tmp->back = NULL;
	find->next = list;
	list->next = NULL;
	list->back = find;
	return (tmp);
}

t_order	*ft_ra(t_order *list_a, t_print *mob)
{
	t_print *tmp;

	mob = find_list_print(mob);
	tmp = malloc(sizeof(t_print) * 1);
	tmp->id = 3;
	mob->next = tmp;
	tmp->next = NULL;
	list_a = rotate(list_a);
	//ft_printf("ra\n");
	return (list_a);
}

t_order	*ft_rb(t_order *list_b, t_print *mob)
{
	t_print *tmp;

	mob = find_list_print(mob);
	tmp = malloc(sizeof(t_print) * 1);
	tmp->id = -3;
	mob->next = tmp;
	tmp->next = NULL;
	list_b = rotate(list_b);
	//ft_printf("rb\n");
	return (list_b);
}

void	ft_rr(t_order *list_a, t_order *list_b)
{
	list_a = rotate(list_a);
	list_b = rotate(list_b);
}

