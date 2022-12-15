/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:29:05 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/15 17:18:29 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_order	*to_next(t_order *list, int out, int position) //pruebas
{
	list->next = create_new_block(list, out, position);
	list = list->next;
	return (list);
}

t_order	*find_end_list(t_order *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

int	ft_struclen(t_order *list)
{
	int count;

	count = 0;
	list = find_first_list(list);
	while (list->next != NULL)
	{
		list = list->next;
		count++;
	}
	return (count);
}

t_order	*find_first_list(t_order *list)
{
	while (list->back != NULL)
	{
		//ft_printf("()%d-%d-%p\n", list->number, list->position, &list);
		list = list->back;
	}
	return (list);
}

int	check_uniq_number(t_order *list, int num)
{
	int	len;
	int	i;

	i = 0;
	if (list == NULL)
		return (1);
	len = ft_struclen(list) + 1;
	list = find_first_list(list);
	while (len > i++)
	{
		if (list->number == num)
		{
			ft_printf("Error:\n Numoros repetios");
			exit(0);
		}
		list = list->next;
	}
	return(1);
}
