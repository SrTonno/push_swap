/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:07:10 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/27 18:26:58 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_order	*reverse(t_order *list) //revisar funcion
{
	t_order	*find;
	t_order	*aux;

	list = find_first_list(list);
	aux = list;
	while (aux->next->next)
		aux = aux->next;
	find = find_end_list(list);
	find->next = list;
	find->back = NULL;
	list->back = find;
	aux->next = NULL;
	return (find);
}

t_order	*ft_rra(t_order *list_a, t_print *mob)
{
	t_print *tmp;

	mob = find_list_print(mob);
	tmp = malloc(sizeof(t_print) * 1);
	tmp->id = 2;
	mob->next = tmp;
	tmp->next = NULL;
	list_a = reverse(list_a);
	//ft_printf("rra\n");
	return(list_a);
}

t_order	*ft_rrb(t_order *list_b, t_print *mob)
{
	t_print *tmp;

	mob = find_list_print(mob);
	tmp = malloc(sizeof(t_print) * 1);
	tmp->id = -2;
	mob->next = tmp;
	tmp->next = NULL;
	list_b = reverse(list_b);
	//ft_printf("rrb\n");
	return(list_b);
}

void	ft_rrr(t_order *list_a, t_order *list_b)
{
	list_a = reverse(list_a);
	list_b = reverse(list_b);
	ft_printf("rrr\n");
}
