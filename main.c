/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:44:34 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/01 16:15:14 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_cosas(t_order *list_a)
{
	list_a = find_first_list(list_a);
	ft_printf("////////////\n");
	while (list_a->next != NULL)
	{
		ft_printf("$/$%d/%d\n", list_a->number, list_a->index);
		list_a = list_a->next;
	}
	ft_printf("$/$%d/%d\n", list_a->number, list_a->index);
	ft_printf("////////////\n");
}

int main(int argc, char **argv)
{
	t_order		*list_a;
	int			len;
	t_print		*mob;

	if (argc < 2)
	{
		ft_printf("Error\n faltan argumentos");
		return (0);
	}
	mob = malloc(1 * sizeof(t_print));
	mob->id = 0;
	mob->next = NULL;
	list_a = NULL;
	list_a = create_list(argv, list_a);
	len = ft_struclen(list_a);
	if (len == 1)
		two_list(list_a, mob);
	else if (len == 2)
		small_list(list_a, mob);
	else if (len < 5)
		list_a = five_number(list_a, mob);
	else if (len < 100)
		list_a = hundred_number(list_a, mob);
	else
		radix(list_a, mob);
	if (mob->next != NULL)
		print_list(mob);
	struct_free(list_a, mob);
}
