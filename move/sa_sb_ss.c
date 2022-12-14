/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:22:36 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/14 11:54:47 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_order	*sa_sb(t_order *list)
{
	t_order	*tmp;
	int		aux;
	int		len;

	len = ft_struclen(list);
	if (len <= 1)
		return (list);
	tmp = list->next;
	aux = list->number;
	list->number = tmp->number;
	tmp->number = aux;
	return (list);
}

void	ss(t_order *list_a, t_order *list_b)
{
	list_a = sa_sb(list_a);
	list_b = sa_sb(list_b);
}
