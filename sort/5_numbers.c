/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_numbers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:10:23 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/01 16:17:40 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_order	*five_number(t_order *list_a, t_print *mob)
{
	t_order	*list_b;

	if (check_order_struck_asd(list_a) == 1)
		return (list_a);
	list_b = ft_calloc(1, sizeof(t_order));
	list_a = find_first_list(list_a);
	list_a = push_min_to_b(list_a, list_b, mob);
	list_a = push_min_to_b(list_a, list_b, mob);
	small_list(list_a, mob);
	ft_pa(list_b, list_a, mob);
	ft_pa(list_b, list_a, mob);
	return (list_a);
}
