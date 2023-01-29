/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   created_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:35:35 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/29 19:41:13 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//Solluionar Fallo de parseo de cuando el ultimo es el mas grande no le asigna un numero
static int	search_min(t_order *list, int len)
{
	int	min;
	int	i;

	i = 0;
	//(void)len;
	list = find_first_list(list);
	while (len > i++)
	{
		if (list->index == -1)
		{
			min = list->number;
			break ;
		}
		if (list->next != NULL)
			list = list->next;
	}
	//list = list->next;
	while (len >= i++)
	{
		if ( list->next != NULL)
			list = list->next;
		if (min > list->number && list->index == -1)
			min = list->number;
	}
	return (min);

}
void	created_index(t_order *list)
{
	int	min;
	int	len;
	int	index;
	t_header	header;
	int	i;
	int	j;

	i = 0;
	index = 0;
	len = ft_struclen(list);
	header.first = find_first_list(list);
	while (len >= i++)
	{
		list = header.first;
		min = search_min(list, len);
		j = 0;
		while (len >= j++)
		{
			if (list->number == min)
			{
				list->index = index++;
				//ft_printf("$/$%d-%d\n", list->number, list->index);
			}
			list = list->next;
		}
	}
	ft_printf("Aaa\n");
	//if (list->next != NULL)
		//list = find_end_list(list);

	//if (list->index == -1)
		//list->index = index++;
}
