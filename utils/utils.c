/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:53:08 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/03 12:41:34 by tvillare         ###   ########.fr       */
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

int	is_only_cezoc(char *num, int i)
{
	while (num[i] == '\0' || num[i] == '+' || num[i] == '-')
	{
		if (num[i] == '0')
			i++;
		else if (num[i] == '+' || num[i] == '-')
			return (i);
		else
			return (-1);
	}
	return (0);
}
int check_max_int(char *org, char *trans)
{
	int	i;
	int	len;
	int	check_a;
	int	check_b;

	len = ft_strlen(org);
	i = 0;
	while (i < len)
	{
		if (org[i] == '+')
			i++;
		else if (org[i] == '0' && trans[i] == '0')
		{
			check_a = is_only_cezoc(org, i + 1);
			check_b = is_only_cezoc(org, i + 1);
			if (check_a == 0)
				break ;
			if (check_a > 0)
			{
				if (org[check_a] == trans[i] || org[check_a] == '+')
					break ;
			}
		}
		else if (org[i] == trans[i])
			i++;
		else
		{
			ft_putstr_fd("Error\n int max", 2);
			exit (1);
		}
	}
	return (ft_atoi(org));

}
