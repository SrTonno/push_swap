/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:34:36 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/19 18:40:29 by tvillare         ###   ########.fr       */
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
#include "../push_swap.h"

static int	find_to_top(t_order *list_b, int min, int max)
{
	int	count;

	count = 0;
	list_b = find_first_list(list_b);
	while (max != list_b->number || min != list_b->number)
	{
		count++;
		list_b = list_b->next;
	}
	return (count);

}

static int	find_to_under(t_order *list_b, int min, int max)
{
	int	count;

	count = 0;
	list_b = find_end_list(list_b);
	while (max != list_b->number || min != list_b->number)
	{
		count++;
		list_b = list_b->back;
	}
	return (count + 1);

}

//static t_order	move_to_a(t_order *list_a, t_order *list_b, int max, int min)


void return_to_a(t_order *list_a, t_order *list_b)
{
	int	max;
	int	min;
	int	i;

	i = 0;
	while (20 > i++)
	{
		max = find_max_value(list_b);
		min = find_min_value(list_b);
		list_b = find_first_list(list_b);
		if (find_to_top(list_b, min, max)
			> find_to_under(list_b, min, max)) // mover desde abajo
		{
			while(max != list_b->number || min != list_b->number)
				list_b = ft_rrb(list_b);
			list_b = list_b->next;
			ft_pa(list_b, list_a);
		}
		else//mover desde arriba
		{
			while(max != list_b->number || min != list_b->number)
				list_b = ft_rb(list_b);
			list_b = list_b->next;
			ft_pa(list_b, list_a);
		}
		list_a = find_first_list(list_a);
		if (min == list_a->number)
			list_a = ft_ra(list_a);
	}
}


t_order	*hundred_number(t_order *list_a)
{
	t_order *list_b;

	list_b = ft_calloc(1, sizeof(t_order));
	list_a = move_block_b(list_a, list_b, 80, 100);
	return_to_a(list_a, list_b);
	return (list_a);
}

