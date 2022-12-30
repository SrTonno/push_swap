/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_numbers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:10:23 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/30 11:50:18 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_order	*five_number(t_order *list_a)
{
	t_order	*list_b;

	if (check_order_struck_asd(list_a) == 1)
		return (list_a);
	list_b = ft_calloc(1, sizeof(t_order));
	list_a = find_first_list(list_a);
	list_a = push_min_to_b(list_a, list_b);
	//list_a = list_a->next;
	list_a = push_min_to_b(list_a, list_b);
	small_list(list_a);
	ft_pa(list_b, list_a);
	ft_pa(list_b, list_a);
	return (list_a);
}
