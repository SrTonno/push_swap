/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:44:34 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/15 13:11:36 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_order	*selector_len(t_order *list_a, t_print *mob, int len)
{
	if (len == 0)
		return (list_a);
	else if (check_order_struck_asd(list_a) == 1)
		return (list_a);
	else if (len == 1)
		two_list(list_a, mob);
	else if (len == 2)
		small_list(list_a, mob);
	else if (len < 7)
		list_a = five_number(list_a, mob);
	else
		radix(list_a, mob);
	list_a = find_first_list(list_a);
	return (list_a);
}

int	main(int argc, char **argv)
{
	t_order		*list_a;
	int			len;
	t_print		*mob;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n Invalid arguments", 2);
		return (0);
	}
	mob = malloc(1 * sizeof(t_print));
	mob->id = 0;
	mob->next = NULL;
	list_a = NULL;
	list_a = create_list(argv, list_a);
	len = ft_struclen(list_a);
	created_index(list_a, len);
	list_a = selector_len(list_a, mob, len);
	if (mob->next != NULL)
		print_list(mob);
	struct_free(list_a, mob);
	return (0);
}
