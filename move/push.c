/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:20:19 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/15 11:24:22 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_order *org, t_order *dst)
{
	t_order	*tmp;

	org = find_first_list(org);
	dst = find_first_list(dst);
	tmp = org;
	org = org->next;
	org->back = NULL;
	tmp->next = dst;
	dst->back = tmp;
	dst = dst->back;
}

void	ft_pa(t_order *list_b, t_order *list_a)
{
	push(list_b, list_a);
	ft_printf("pa\n");
}

void	ft_pb(t_order *list_b, t_order *list_a)
{
	push(list_a, list_b);
	ft_printf("pb\n");
}
