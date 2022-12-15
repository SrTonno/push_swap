/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:44:34 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/15 19:07:12 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char **argv)
{
	int i;
	t_order		*list_a;
	t_order		*list_b;
	t_header	header;

	if (argc < 2)
	{
		ft_printf("Error:\n faltan argumentos");
		return (0);
	}
	list_a = NULL;
	list_b = NULL;
	i = 0;
	list_a = create_list(argv, list_a);
	//list_b = create_list(argv, list_a);
	header.first = list_a;
	//while (list_a->next != NULL)
	//small_list(list_a);
	//list_a = find_first_list(list_a);
	list_a = five_number(list_a);
	list_a = find_first_list(list_a);
	/*ft_printf("////////////\n");
	while (list_a->next != NULL)
	{
		ft_printf("$/$%d\n", list_a->number);
		list_a = list_a->next;
	}
	ft_printf("$/$%d\n", list_a->number);
	ft_printf("////////////\n");*/
}
