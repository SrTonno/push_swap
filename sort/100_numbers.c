/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:34:36 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/21 16:01:32 by tvillare         ###   ########.fr       */
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

t_order	*hundred_number(t_order *list_a)
{
	t_order *list_b;
	int	max;
	int	min;
	int	i;

	max = 15;
	min = 12;
	i = 1;
	//while (i--)
	//{
		list_b = ft_calloc(1, sizeof(t_order));
		list_a = move_block_b(list_a, list_b, min, max);
		if (i != 4)
			min_to_top (list_a, min);
		//return_to_a(list_a, list_b, 4);
		if (min != 0)
		{
			max -= 4;
			min -= 4;
		}
	//}
	min_to_top (list_a, -1);
	return (list_a);
}

