
#include "push_swap.h"

static void	*create_new_block(t_order *list_a, int out, int position)
{
	t_order	tmp;

	tmp.number = out;
	tmp.position = position;
	tmp.back = list_a;
	/*while (list_a->next)
	{

		list_a = list_a->next;
	}*/
	list_a->next = &tmp;
	list_a = list_a->next;
	ft_printf("%d-%d\n", list_a->number, list_a->position);
	return (list_a);
}
static int	check_number(char *number)
{
	int len;
	int i;

	len = ft_strlen(number);
	i = -1;
	while ((len - 1) > ++i)
	{
		//ft_printf("%c", number[i]);
		if ('0' > number[i] || number[i] > '9')
		{
			//ft_printf("Error:\n list not a number");
			exit(0);
		}
	}
	return (ft_atoi(number));
}

static void str_to_list(char *str, int position, t_order list_a)
{
	char	**number;
	int		col;
	int		out;

	col = -1;
	number = ft_split(str, ' ');
	while (number[++col] != '\0')
	{
		out = check_number(number[col]);
	}
	//insertar en la cadena enlazada
}

t_list create_list(char **raw, int max)
{
	int out;
	int	position;
	int	i;
	t_list	*list_a;
	t_list	*tmp;;


	//tmp = list_a;
	position = 0;
	i = 0;
	//comprobar si tiene espacions
	while (max - 1 > i)
	{
		out = check_number(raw[i]);
		if (position == 0)
		{
			list_a = ft_lstnew(out);
		}
		else
		{
			//create_new_block(&list_a, out, position);
			tmp->content = ft_lstnew((void *)out);

			ft_lstadd_back((list_a **)list_a, tmp);

		//ft_printf("%d-%d\n", list_a.number, list_a.position);
		position++;
		i++;
		}
	list_a->next = NULL;
	/*while (list_a != NULL)
	{

		ft_printf("//%d-%d\n", list_a.number, list_a.position);
		list_a = *list_a.back;
	}*/
	return (*list_a);
}
}

int main()
{
	char **i;
	t_list list_a;

	i = ft_split("123 456 789", ' ');
	list_a = create_list(i, 4);
	/*while (list_a.back != NULL)
	{
		ft_printf("$$%d-%d\n", list_a.number, list_a.position);
		list_a = *list_a.back;
	}*/

}
