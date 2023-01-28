/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:22:36 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/28 12:11:13 by tvillare         ###   ########.fr       */
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
	t_print *tmp;

	mob = find_list_print(mob);
	tmp = malloc(sizeof(t_print) * 1);
	tmp->id = 4;
	mob->next = tmp;
	tmp->next = NULL;
	list_a = swap(list_a);
	//ft_printf("sa\n");
	return (list_a);
}
t_order	*ft_sb(t_order *list_b, t_print *mob)
{
	t_print *tmp;

	mob = find_list_print(mob);
	tmp = malloc(sizeof(t_print) * 1);
	tmp->id = -4;
	mob->next = tmp;
	tmp->next = NULL;
	list_b = swap(list_b);
	//ft_printf("sb\n");
	return (list_b);
}

void	ft_ss(t_order *list_a, t_order *list_b)
{
	list_a = swap(list_a);
	list_b = swap(list_b);
	ft_printf("ss\n");
}
