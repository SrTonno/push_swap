/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psorder_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:43:50 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/30 11:27:01 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_order	*psorder(t_order *list)
{
	t_order	*aux;

	list = find_first_list(list);
	aux = find_end_list(list);
	if (list->index < aux->index)
		list = ft_rrb(list);
	else if (list->index < list->next->index
	&& ft_struclen(list) > 1)
		list = ft_sb(list);
	return (list);
}

static int	num_position(t_order *list, int num)
{
	int	len;
	int	i;

	len = ft_struclen(list);
	i = 0;
	list = find_first_list(list);
	while (list->next != NULL)
	{
		i++;
		if (list->index == num)
			break ;
		list = list->next;
	}
	return (i);
}

void	total_return(t_order *org, t_order *dst, int top)
{
	int	post;
	t_order	*tmp;

	org = find_first_list(org);
	while (top > 0)
	{

		post = num_position(org, top);
		if (top / 2 > post && top != 0)
			while (org->index != top)
				org = ft_rb(org);
		else
			while (org->index != top)
				org = ft_rrb(org);
		tmp = org->next;
		ft_pa(org, dst);
		org = tmp;
		top--;
	}
	ft_pa(org, dst);
	dst = find_first_list(dst);
	//print_cosas(dst);
}
