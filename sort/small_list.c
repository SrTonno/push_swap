/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:01:12 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/15 18:20:44 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	small_list(t_order *list_a)
{
	list_a = find_first_list(list_a);
	if (check_order_struck_asd(list_a) == 1)
		return ;
	else if (check_order_struck_dst(list_a) == 1)
	{
		list_a = ft_ra(list_a);
		list_a = ft_sa(list_a);
		return ;
	}
	while (check_order_struck_asd(list_a) != 1)
	{
		if (list_a->number > list_a->next->number)
			list_a = ft_sa(list_a);
		else if (list_a->number > list_a->next->next->number)
			list_a = ft_rra(list_a);
		else if (list_a->number < list_a->next->next->number)
			list_a = ft_ra(list_a);
	}

}

