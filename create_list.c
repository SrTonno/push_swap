/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:13:30 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/13 11:51:45 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_order	*create_new_block(t_order *list_a, int out, int position)
{
	t_order	*tmp;

	tmp = ft_calloc(1, sizeof(t_order));
	tmp->number = out;
	tmp->position = position;
	tmp->back = list_a;
	list_a->next = tmp;
	return (tmp);
}

static t_order	*praimal_list(int out)
{
	t_order	*tmp;

	tmp = ft_calloc(1, sizeof(t_order));
	ft_printf("\n%d\n", out);
	tmp->number = out;
	tmp->position = 0;
	tmp->back = NULL;
	return (tmp);
}

static int	check_number(char *number)
{
	int len;
	int i;

	len = ft_strlen(number);
	i = -1;
	while (len > ++i)
	{
		//ft_printf("%c", number[i]);
		if ('0' > number[i] || number[i] > '9')
		{
			ft_printf("Error:\n list not a number");
			exit(0);
		}
	}
	return (ft_atoi(number));
}

static void *str_to_list(char *str, int position, t_order *list_a)
{
	char	**number;
	int		col;
	int		out;
	int		i;
	t_header	header;

	col = -1;
	number = ft_split(str, '/');
	while (number[++col] != '\0')
	{
		out = check_number(number[col]);
		if (position == 0)
		{
			list_a = praimal_list(out);
			header.first = list_a;
			ft_printf("&%d-%d-%p\n", list_a->number, list_a->position, list_a);
		}
		else
		{
			list_a->next = create_new_block(list_a, out, position);
			list_a = list_a->next;
			ft_printf("@%d-%d-%p\n", list_a->number, list_a->position, list_a);
		}
		if (position != 0 && i == 0)
			header.first = list_a;
		//ft_printf("%d-%d\n", list_a->number, list_a->position);
		position++;
		i++;
	}
	list_a->next = NULL;
	return (header.first);
}

t_order	*create_list(char **raw, int max)
{
	int			out;
	int			position;
	int			i;
	t_order		*list_a;
	t_order		*tmp;
	t_header	header;

	//tmp = list_a;
	position = 0;
	i = 0;

	//comprobar si tiene espacions
	//tmp = malloc(1 * sizeof(t_order));
	while (max - 1 > i)
	{
		if (ft_strchr(raw[i], '/'))
		{
			list_a = str_to_list(raw[i], position, list_a);
			i++;
			list_a = list_a->next;
		}
		out = check_number(raw[i]);

		if (position == 0)
		{
			list_a = praimal_list(out);
			header.first = list_a;
			ft_printf("&%d-%d-%p\n", list_a->number, list_a->position, list_a);
		}
		else
		{
			list_a->next = create_new_block(list_a, out, position);
			list_a = list_a->next;
			ft_printf("@%d-%d-%p\n", list_a->number, list_a->position, list_a);
		}

		//ft_printf("%d-%d\n", list_a->number, list_a->position);
		position++;
		i++;
	}
	list_a->next = NULL;
	/*while (list_a->back != NULL)
	{

		ft_printf("//%d-%d\n", list_a->number, list_a->position);
		list_a = list_a->back;
	}*/

	ft_printf("(header)%d-%d-%p\n", header.first->number, header.first->position, header);
	return (header.first);
}

int main()
{
	char **out;
	int i;
	t_order *list_a;
	i = -1;

	out = ft_split("123 456 789 147 258", ' ');
	/*while (5 > i)
	{
		ft_printf("%s\n", out[i++]);
	}*/

	list_a = create_list(out, 6);
	system("leaks -q push_swap");

	//while (list_a->next != NULL)
	while (5 > ++i)
	{
		ft_printf("$/$%d-%d-%p\n", list_a->number, list_a->position, &list_a);
		list_a = list_a->next;
	}
}
