/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:51:25 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/08 12:12:42 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	struct_free(t_order *list, t_print *mob)
{
	t_order	*tmp;
	t_print	*aux;

	list = find_first_list(list);
	if (list != NULL)
	{
		while (list->next != NULL)
		{
			tmp = list;
			list = list->next;
			free(tmp);
		}
		free(list);
	}
	if (mob != NULL)
	{
		while (mob->next != NULL)
		{
			aux = mob;
			mob = mob->next;
			free(aux);
		}
		free(mob);
	}
}
