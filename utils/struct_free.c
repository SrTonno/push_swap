/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:51:25 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/21 18:54:39 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	struct_free(t_order *list)
{
	t_order *tmp;

	while (list->next != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	free(list);
}
