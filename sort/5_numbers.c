/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_numbers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:10:23 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/08 13:02:26 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_order	*five_number(t_order *list_a, t_print *mob)
{
	t_order	*list_b;
	int		len_b;

	if (check_order_struck_asd(list_a) == 1)
		return (list_a);
	list_b = ft_calloc(1, sizeof(t_order));
	list_a = find_first_list(list_a);
	list_a = push_min_to_b(list_a, list_b, mob);
	if (ft_struclen(list_a) >= 3)
		list_a = push_min_to_b(list_a, list_b, mob);
	if (ft_struclen(list_a) >= 3)
		list_a = push_min_to_b(list_a, list_b, mob);
	if (ft_struclen(list_a) >= 3)
		list_a = push_min_to_b(list_a, list_b, mob);
	small_list(list_a, mob);
	len_b = ft_struclen(list_b);
	ft_pa(list_b, list_a, mob);
	if (len_b >= 2)
		ft_pa(list_b, list_a, mob);
	if (len_b >= 3)
		ft_pa(list_b, list_a, mob);
	if (len_b >= 4)
		ft_pa(list_b, list_a, mob);
	if (list_b != NULL)
		free(list_b);
	return (list_a);
}
