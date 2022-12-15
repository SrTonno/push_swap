/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:53:08 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/15 13:25:33 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void	free_map(char **map)
{
	int	count;

	count = 0;
	while (map[count] != '\0')
	{
		free(map[count++]);
	}
	free(map);

}
