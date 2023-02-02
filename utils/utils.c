/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:53:08 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/02 16:48:18 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_map(char **map)
{
	int	count;

	count = 0;
	while (map[count] != '\0')
		free(map[count++]);
	free(map);
}

void	add_block_mob(t_print *mob, int type)
{
	t_print	*tmp;

	mob = find_list_print(mob);
	tmp = malloc(sizeof(t_print) * 1);
	tmp->id = type;
	mob->next = tmp;
	tmp->next = NULL;
}
