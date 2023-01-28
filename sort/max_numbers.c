/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:34:36 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/28 13:23:07 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1.-Pasar x% a b y ir Pseudoornenado los datos
2.-Ordenar ultimos numeros
3.-Pasar los nummeros ordenados de mañor a menor
*/
//https://gitlab.com/42cursus-wetieven/23-push-swap

//https://www.ugr.es/~jsalinas/Aleatorios.htm
#include "../push_swap.h"

static int	max_index(t_order *list)
{
	int	len;
	int	max;
	int	i;

	i = 0;
	list = find_first_list(list);
	len = ft_struclen(list);
	max = list->index;
	list = list->next;
	while (len > i++)
	{
		if (max < list->index)
			max = list->index;
		list = list->next;
	}
	//ft_printf("x%dx", min);
	return (max);

}

/*
1.- Pasar todos en el bit mas significativo(000001) 0 a b
2.- Ordenar b
3.- pasar b to a
4.- reperir el paso 1 al 3 pero con un bit mas hacia la derecha (000010)
*/


t_order	*max_number(t_order *list_a, t_print *mob)
{
	t_order *list_b;
	int	limits[2];
	int	top;
	int	i;
	int	interval;

	if (check_order_struck_asd(list_a) == 1)
		return (list_a);
	created_index(list_a);
	top = max_index(list_a);
	interval = (top / 14) + 1;
	limits[0] = 0;
	limits[1] = limits[0] + interval;
	//limits[0] = (limits[1] - interval) + 1;
	//ft_printf("/FIN/limits[1] = %d, limits[0] = %d, intelval= %d, limits[1]-limits[0] = %d\n", limits[1], limits[0], interval, (limits[1] - limits[0]));
	i = 0;
	(void)list_b;
	list_a = find_first_list(list_a);
	list_b = ft_calloc(1, sizeof(t_order));
	while (14 > i++)
	{
		//ft_printf("/principio/limits[1] = %d, limits[0] = %d, intelval= %d, limits[1]-limits[0] = %d\n", limits[1], limits[0], interval, (limits[1] - limits[0]));
		list_a = move_block_b(list_a, list_b, limits, mob);
		limits[0] = limits[1] + 1;
		limits[1] = limits[0] + interval;
		if (top - 5 <= limits[1])
			limits[1] = top - 5;
		list_b = find_first_list(list_b);
			//print_cosas(list_b);
		//ft_printf("-%d-", list_b->number);
		//ft_printf("/FIN/limits[1] = %d, limits[0] = %d, intelval= %d, limits[1]-limits[0] = %d\n", limits[1], limits[0], interval, (limits[1] - limits[0]));
	}
	//min_to_top(list_a, -1);
	//print_cosas(list_b);
	list_a = five_number(list_a, mob);
	total_return(list_b, list_a, top - 5, mob);
	//ft_printf("-----------FIN------\n");
	list_a = find_first_list(list_a);
	//print_cosas(list_a);

	//print_cosas(list_b);
	//ft_printf("()%d|\n", check_order_struck_asd(list_a));
	return (list_a);
}

