/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:01:12 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/27 18:44:27 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	small_list(t_order *list_a)
{
	list_a = find_first_list(list_a);
	if (check_order_struck_asd(list_a) == 1)
		return ;
	else if (list_a->number > list_a->next->number
		&& list_a->next->number < list_a->next->next->number
		&& list_a->number < list_a->next->next->number)
		list_a = ft_sa(list_a);
	else if (list_a->number > list_a->next->number
		&& list_a->next->number > list_a->next->next->number)
	{
		list_a = ft_sa(list_a);
		list_a = ft_rra(list_a);
	}
	else if (list_a->number > list_a->next->number
		&& list_a->next->number < list_a->next->next->number)
			list_a = ft_ra(list_a);
	else if (list_a->number < list_a->next->number
		&& list_a->next->number > list_a->next->next->number
		&& list_a->number < list_a->next->next->number)
	{
		list_a = ft_sa(list_a);
		list_a = ft_ra(list_a);
	}
	else
		list_a = ft_rra(list_a);
}

//else (list_a->number > list_a->next->number
		//&& list_a->next->number < list_a->next->next->number)
