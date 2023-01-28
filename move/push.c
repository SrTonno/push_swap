/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:20:19 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/27 18:25:56 by tvillare         ###   ########.fr       */
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
	dst = find_first_list(dst);
	tmp->next = dst;
	dst->back = tmp;
	dst = dst->back;
}

void	ft_pa(t_order *list_b, t_order *list_a, t_print *mob)
{
	t_print *tmp;

	mob = find_list_print(mob);
	tmp = malloc(sizeof(t_print) * 1);
	tmp->id = 1;
	tmp->next = NULL;
	mob->next = tmp;
	push(list_b, list_a);
	//ft_printf("pa\n");
}

void	ft_pb(t_order *list_a, t_order *list_b, t_print *mob)
{
	t_print *tmp;

	mob = find_list_print(mob);
	tmp = malloc(sizeof(t_print) * 1);
	tmp->id = -1;
	mob->next = tmp;
	tmp->next = NULL;
	push(list_a, list_b);
	//ft_printf("pb\n");
}
