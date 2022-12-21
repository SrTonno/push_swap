/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:44:34 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/21 18:01:36 by tvillare         ###   ########.fr       */
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
	int i;
	t_order		*list_a;
	t_order		*list_b;
	t_header	header;
	//int			len;

	if (argc < 2)
	{
		ft_printf("Error:\n faltan argumentos");
		return (0);
	}
	list_a = NULL;
	list_b = NULL;
	//list_b = ft_calloc(1, sizeof(t_order));
	i = 0;
	list_a = create_list(argv, list_a);
	//list_b = create_list(argv, list_a);
	header.first = list_a;
	//while (list_a->next != NULL)
	//small_list(list_a);
	//list_a = find_first_list(list_a);
	//len = ft_struclen(list_a);
	/*if (len < 3)
		small_list(list_a);
	else if (len < 5)
		list_a = five_number(list_a);
	else if (len < 100)
		list_a = hundred_number(list_a);*/
	list_a = find_first_list(list_a);
	created_index(list_a);
	list_a = find_first_list(list_a);
	hundred_number(list_a);
	list_a = find_first_list(list_a);
	print_cosas(list_a);
}
