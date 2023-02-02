/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:14:36 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/02 16:33:01 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_order_struck_asd(t_order *list)
{
	int	aux;
	int	len;
	int	i;

	i = 0;
	list = find_first_list(list);
	len = ft_struclen(list);
	aux = list->number;
	while (len >= i++)
	{
		if (aux > list->number)
			return (0);
		aux = list->number;
		list = list->next;
	}
	return (1);
}

int	check_order_struck_dst(t_order *list)
{
	int	aux;
	int	len;
	int	i;

	i = 0;
	list = find_first_list(list);
	len = ft_struclen(list);
	aux = list->number;
	while (len >= i++)
	{
		if (aux < list->number)
			return (0);
		aux = list->number;
		list = list->next;
	}
	return (1);
}

int	find_min_value(t_order *list)
{
	int	len;
	int	min;
	int	i;

	i = 0;
	list = find_first_list(list);
	len = ft_struclen(list);
	min = list->number;
	list = list->next;
	while (len > i++)
	{
		if (min > list->number)
			min = list->number;
		list = list->next;
	}
	return (min);
}

int	find_max_value(t_order *list)
{
	int	len;
	int	max;
	int	i;

	i = 0;
	list = find_first_list(list);
	len = ft_struclen(list);
	max = list->number;
	list = list->next;
	while (len > i++)
	{
		if (max < list->number)
			max = list->number;
		list = list->next;
	}
	return (max);
}
