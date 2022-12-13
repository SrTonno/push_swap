#include "push_swap.h"



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

		out = check_number(raw[i]);
		tmp = malloc(1 * sizeof(t_order));
		if (position == 0)
		{
			ft_printf("\n%d\n", out);
			tmp->number = out;
			tmp->position = position;
			tmp->back = NULL;
			list_a = tmp;
			header.first = list_a;
			ft_printf("&%d-%d-%p\n", list_a->number, list_a->position, list_a);
		}
		else
		{
			//create_new_block(&list_a, out, position);
			tmp->number = out;
			tmp->position = position;
			tmp->back = list_a;
			list_a->next = tmp;

			//list_a->next = create_new_block(list_a, out, position);
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
