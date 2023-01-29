/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:08:58 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/29 19:26:46 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*
1.- Pasar a 'b' todos los que tengan 0 en el primer bit.
2.-Pasar de 'b' a 'a'
3.- Repetir pasos 1 y 2 pero en el sigiente bit
*/
static int	mult_2(int num)
{
	int	mult;
	int	count;
	int aux;

	count = 0;
	mult = 1;
	ft_printf("num:%d\n", num);
	while (num > mult)
	{
		aux = mult;
		mult *= 2;
		if (mult - 1 >= num && aux < num)
			return (count);
		count++;
	}
	return (count);
}

static void	push_zero(t_order *list_a, t_order *list_b, t_print *mob, int mult)
{
	int	count;
	int	max;

	max = ft_struclen(list_a);
	count = 0;
	list_a = find_first_list(list_a);
	while (max > count++)
	{
		if (list_a->index & mult)
			ft_pb(list_a, list_b, mob);
		list_a = ft_ra(list_a, mob);
	}
}

static void	return_zero(t_order *list_a, t_order *list_b, t_print *mob)
{
	int	count;
	int	max;

	max = ft_struclen(list_b);
	count = 0;
	list_b = find_first_list(list_b);
	while (max > count++)
	{
		ft_pa(list_b, list_a, mob);
		list_b = ft_rb(list_b, mob);
	}
}

void	radix(t_order *list_a, t_print *mob)
{
	t_order	*list_b;
	int		mult;
	int		max;
	int		count;

	mult = 1;
	count = 1;
	created_index(list_a);
	max = mult_2(ft_struclen(list_a) + 1);
	ft_printf("%d\n", max);
	//while(max >= count)
	//{
		//print_cosas(list_a);
		list_b = malloc(1 * sizeof(t_order));
		push_zero(list_a, list_b, mob, mult);
		//print_cosas(list_b);
		return_zero(list_a, list_a, mob);
		count++;
		mult *= 2;
	//}
}
