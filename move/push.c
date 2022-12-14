/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:20:19 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/14 12:44:20 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_order	*push(t_order *org, t_order *dst)
{
	t_order	*tmp;

	tmp = org;
	org = org->next;
	tmp->next = dst;
	return (tmp);
}
