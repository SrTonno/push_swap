/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:22:36 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/15 11:25:56 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_order	*swap(t_order *list)
{
	t_order	*tmp;
	int		aux;
	int		len;

	list = find_first_list(list);
	len = ft_struclen(list);
	if (len <= 1)
		return (list);
	tmp = list->next;
	aux = list->number;
	list->number = tmp->number;
	tmp->number = aux;
	return (list);
}
t_order	*ft_sa(t_order *list_a)
{
	list_a = swap(list_a);
	ft_printf("sa\n");
	return (list_a);
}
t_order	*ft_sb(t_order *list_b)
{
	list_b = swap(list_b);
	ft_printf("sb\n");
	return (list_b);
}

void	ft_ss(t_order *list_a, t_order *list_b)
{
	list_a = swap(list_a);
	list_b = swap(list_b);
	ft_printf("ss\n");
}
