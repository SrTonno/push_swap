/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:20:19 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/02 16:53:30 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_order *org, t_order *dst)
{
	t_order	*tmp;

	if (org == NULL)
		return ;
	org = find_first_list(org);
	if (org->next != NULL)
	{
		tmp = org;
		org = org->next;
		org->back = NULL;
	}
	else
		tmp = org;
	if (dst != NULL)
		dst = find_first_list(dst);
	tmp->next = dst;
	dst->back = tmp;
	dst = dst->back;
	tmp->back = NULL;
}

void	ft_pa(t_order *list_b, t_order *list_a, t_print *mob)
{
	add_block_mob(mob, 1);
	push(list_b, list_a);
}

void	ft_pb(t_order *list_a, t_order *list_b, t_print *mob)
{
	add_block_mob(mob, -1);
	push(list_a, list_b);
}
