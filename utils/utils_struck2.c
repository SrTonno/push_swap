/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struck2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:41:26 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/19 17:36:00 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//struct
//struct
static t_order	*up_to_min(t_order *list, int min, int i, int len)
{
	list = find_first_list(list);
	while (list->number != min)
	{
		if (i == 2)
			list = ft_sa(list);
		else if (len < i)
			list = ft_rra(list);
		else if (len / 2 < i)
			list = ft_rra(list);
		else
			list = ft_ra(list);
	}
	return (list);
}

t_order	*push_min_to_b(t_order *list_a, t_order *list_b)
{
	int		len;
	int		i;
	int		min;
	t_order	*tmp;

	list_a = find_first_list(list_a);
	len = ft_struclen(list_a);
	min = find_min_value(list_a);
	i = 0;
	tmp = NULL;
	while (len >= i++)
	{
		if (list_a->number == min)
		{
			list_a = up_to_min(list_a, min, i, len);
			//if (list_a->next != NULL)
				tmp = list_a->next;
			/*else
				tmp = list_a->back;*/
			ft_pb(list_a, list_b);
			return (tmp);
		}
		list_a = list_a->next;
	}
	return (tmp);
}

