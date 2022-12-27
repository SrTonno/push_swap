/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struck2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:41:26 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/27 19:02:08 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//struct
//struct
static t_order	*up_to_min(t_order *list, int min, int i)
{
	list = find_first_list(list);
	while (list->number != min)
	{
		if (2 < i)
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
			list_a = up_to_min(list_a, min, i);
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

int	top_or_under(t_order *list, int num)
{
	int	top;
	int	under;

	top = 0;
	under = 0;
	list = find_first_list(list);
	while (list->next != NULL && num != list->index)
	{
		list = list->next;
		top++;
	}
	list = find_end_list(list);
	while (list->back != NULL && num != list->index)
	{
		list = list->back;
		under++;
	}
	if (top > under + 1)
		return (0);
	return (1);


}
t_order	*min_to_top (t_order *list, int max)
{
	int	mode;
	list = find_first_list(list);
	max += 1;
	mode = top_or_under(list, max);
	while (list->index != max)
	{
		if (mode == 1)
			list = ft_ra(list);
		else
			list = ft_rra(list);
		list = find_first_list(list);
	}
	return (list);

}