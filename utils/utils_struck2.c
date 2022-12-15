/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struck2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:41:26 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/15 19:00:20 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//struct
t_order	*push_min_to_b(t_order *list_a, t_order *list_b)
{
	int		len;
	int		i;
	int		min;
	t_order	*tmp;

	(void)list_b;
	list_a = find_first_list(list_a);
	len = ft_struclen(list_a);
	min = find_min_value(list_a);
	i = 0;
	tmp = NULL;
	//ft_printf("A\n");
	while(len >= i++)
	{
		if (list_a->number == min)
		{
			list_a = find_first_list(list_a);
			while (list_a->number != min)
			{
			if (i == 2)
				list_a = ft_sa(list_a);
			else if (len < i)
				list_a = ft_rra(list_a);
			else if (len / 2 < i)
				list_a = ft_rra(list_a);
			else
				list_a = ft_ra(list_a);
			}
			if (list_a->next != NULL)
				tmp = list_a->next;
			else
				tmp = list_a->back;
			ft_pb(list_a, list_b);
			return (tmp);
		}
		list_a = list_a->next;
	}
	return (tmp);
}
