/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   created_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:35:35 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/02 16:46:04 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	search_min(t_order *list, int len)
{
	int	min;
	int	i;

	i = 0;
	list = find_first_list(list);
	while (len >= i++)
	{
		if (list->index == -1)
		{
			min = list->number;
			break ;
		}
		if (list->next != NULL)
			list = list->next;
	}
	while (len >= i++)
	{
		if (list->next != NULL)
			list = list->next;
		if (min > list->number && list->index == -1)
			min = list->number;
	}
	return (min);
}

void	created_index(t_order *list, int len)
{
	int			min;
	int			index;
	t_header	header;
	int			i;
	int			j;

	i = 0;
	index = 0;
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
			}
			list = list->next;
		}
	}
}
