/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:44:34 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/28 16:48:47 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void print_cosas(t_order *list_a)
{
	list_a = find_first_list(list_a);
	ft_printf("////////////\n");
	while (list_a->next != NULL)
	{
		ft_printf("$/$%d/%d\n", list_a->number, list_a->index);
		list_a = list_a->next;
	}
	ft_printf("$/$%d/%d\n", list_a->number, list_a->index);
	ft_printf("////////////\n");
}
*/
static int	check_doble(t_print *mob)
{
	if (mob->next == NULL)
		return (0);
	if (mob->id + mob->next->id == 0)
		return (1);
	return (0);
}
static int	types_mob(t_print *mob)
{
	if (mob->id == 1)
		ft_printf("pa\n");
	else if (mob->id == -1)
		ft_printf("pb\n");
	else if	(check_doble(mob) == 1 && (mob->id == 2 || mob->id == -2))
		return (ft_printf("rrr\n"));
	else if (mob->id == 2)
		ft_printf("rra\n");
	else if (mob->id == -2)
		ft_printf("rrb\n");
	else if	(check_doble(mob) == 1 && (mob->id == 3 || mob->id == -3))
		return (ft_printf("rr\n"));
	else if (mob->id == 3)
		ft_printf("ra\n");
	else if (mob->id == -3)
		ft_printf("rb\n");
	else if	(check_doble(mob) == 1 && (mob->id == 4 || mob->id == -4))
		return (ft_printf("ss\n"));
	else if (mob->id == 4)
		ft_printf("sa\n");
	else if (mob->id == -4)
		ft_printf("sb\n");
	return (0);
}

static int	len_print(t_print *mob)
{
	int	count;

	count = 0;
	while (mob->next != NULL)
	{
		mob = mob->next;
		count++;
	}
	return (count);
}

static void	print_list(t_print *mob)
{
	int	skip;
	int	count;
	int	i;
	int	a;

	i = 0;
	a = 0;
	count = len_print(mob);
	mob = mob->next;
	while (i < count)
	{
		skip = types_mob(mob);
		//ft_printf("%d", skip);
		if (skip > 0)
		{
			a++;
			//ft_printf("A\n");
			mob = mob->next;
			i++;
			if (mob->next == NULL)
				return ;
		}
		//if (mob->next != NULL)
		mob = mob->next;
		i++;
	}
	//ft_printf("%d", a);
	//if (skip != 0)
		//types_mob(mob);
}
int main(int argc, char **argv)
{
	int			i;
	t_order		*list_a;
	int			len;
	t_print		*mob;

	if (argc < 2)
	{
		ft_printf("Error\n faltan argumentos");
		return (0);
	}
	mob = malloc(1 * sizeof(t_print));
	mob->id = 0;
	mob->next = NULL;
	list_a = NULL;
	i = 0;
	list_a = create_list(argv, list_a);
	//list_a = find_first_list(list_a);
	len = ft_struclen(list_a);
	if (len == 1)
		two_list(list_a, mob);
	else if (len == 2)
		small_list(list_a, mob);
	else if (len < 5)
		list_a = five_number(list_a, mob);
	else if (len < 100)
		list_a = hundred_number(list_a, mob);
	else
		list_a = max_number(list_a, mob);
	/*
	list_a = ft_ra(list_a, mob);
	list_a = ft_sb(list_a, mob);
	list_a = ft_sb(list_a, mob);
	list_a = ft_sb(list_a, mob);
	list_a = ft_ra(list_a, mob);
	list_a = ft_rb(list_a, mob);
	*/
	//ft_ra(list_a, mob);
	//list_a = find_first_list(list_a);
	//created_index(list_a);
	//list_a = find_first_list(list_a);
	//hundred_number(list_a);
	//list_a = find_first_list(list_a);
	//print_cosas(list_a);
	if (mob->next != NULL)
		print_list(mob);
	struct_free(list_a, mob);
	//system("leaks -q push_swap");
}
