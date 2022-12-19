/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   created_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:35:35 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/19 15:36:48 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	search_min(t_order *list)
{
	int	min;
	int	i;

	i = 0;
	list = find_first_list(list);
	while (list->next != NULL)
	{
		if (list->index != -1)
		{
			min = list->number;
			break ;
		}
		list = list->next;
	}
	while (list->next != NULL)
	{
		if (min > list->number && list->index != -1)
			min = list->number;
		list = list->next;
	}
	return (min);

}
void	created_index(t_order *list)
{
	int	min;
	int	len;
	int	index;
	int	i;
	int	j;

	j = 0;
	i = 0;
	len = ft_struclen(list) + 1;
	index = 0;
	while (len > i++)
	{

		list = find_first_list(list);
		min = search_min(list);
		while (len >= j++)
		{
			if (list->number == min)
				list->index = index++;
			list = list->next;
		}
	}
}
