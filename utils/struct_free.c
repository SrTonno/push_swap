/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:51:25 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/27 17:04:24 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	struct_free(t_order *list, t_print *mob)
{
	t_order	*tmp;
	t_print	*aux;

	while (list->next != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	while (mob->next != NULL)
	{
		aux = mob;
		mob = mob->next;
		free(aux);
	}
	free(list);
	free(mob);
}
