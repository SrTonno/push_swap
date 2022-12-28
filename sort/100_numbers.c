/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:34:36 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/28 17:27:14 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1-Calcular los x% numeros mas grandes o usar indeces
2-Pasar los numeros mas grandes a list_b
3-Debolber los numeros a list_a(si el numero es el mas grande de lis_b solo hacer pa, pero si es el mas pequeño hacer pa y ra(poner el numero al final))
4-repetir los pasos 1 al 3.
5-Comprobar que este bien ordenado
*/
//https://github.com/AdrianWR/push_swap

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
t_order	*hundred_number(t_order *list_a)
{
	t_order *list_b;
	int	max;
	int	min;
	int	i;
	int	interval;

	created_index(list_a);
	max = max_index(list_a);
	interval = max / 4;
	min = (max - interval) + 1;
	//ft_printf("/FIN/max = %d, min = %d, intelval= %d, max-min = %d\n", max, min, interval, (max - min));
	i = 0;
	(void)list_b;
	list_a = find_first_list(list_a);
	while (4 > i++)
	{
		//ft_printf("/principio/max = %d, min = %d, intelval= %d, max-min = %d\n", max, min, interval, (max - min));
		list_b = ft_calloc(1, sizeof(t_order));
		list_a = move_block_b(list_a, list_b, min, max);
		if(i != 1)
			min_to_top(list_a, max);
		return_to_a(list_a, list_b, interval);
		//print_cosas(list_a);
		max = min - 1;
		min = max - interval;
		if (0 > min)
			min = 0;
		interval = (max - min) + 1;
		//ft_printf("/FIN/max = %d, min = %d, intelval= %d, max-min = %d\n", max, min, interval, (max - min));
	}
	min_to_top(list_a, -1);
	return (list_a);
}

