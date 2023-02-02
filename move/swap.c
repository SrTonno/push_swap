/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:22:36 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/02 16:50:00 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_order	*swap(t_order *list)
{
	t_order	*first;
	t_order	*second;
	int		len;

	list = find_first_list(list);
	len = ft_struclen(list);
	if (len <= 1)
		return (list);
	first = list;
	second = list->next;
	list = list->next->next;
	first->next = list;
	first->back = second;
	second->next = first;
	second->back = NULL;
	return (list);
}

t_order	*ft_sa(t_order *list_a, t_print *mob)
{
	add_block_mob(mob, 4);
	list_a = swap(list_a);
	return (list_a);
}

t_order	*ft_sb(t_order *list_b, t_print *mob)
{
	add_block_mob(mob, -4);
	list_b = swap(list_b);
	return (list_b);
}

void	ft_ss(t_order *list_a, t_order *list_b)
{
	list_a = swap(list_a);
	list_b = swap(list_b);
	ft_printf("ss\n");
}
