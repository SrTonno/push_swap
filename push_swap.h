/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:42:37 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/14 13:02:47 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/union_libft.h"
////Strucks
typedef struct s_order
{
	int				number;
	int				position;
	struct s_order	*next;
	struct s_order	*back;
}				t_order;

typedef struct s_header
{
	struct s_order	*first;
}				t_header;

////Funtions
t_order		*find_end_list(t_order *list_a);
t_order		*to_next(t_order *list_a, int out, int position);
t_order		*create_list(char **raw, t_order *list_a);
t_order		*create_new_block(t_order *list_a, int out, int position);
void		free_map(char **map);
int			ft_struclen(t_order *list);
/// Operaciones
t_order		*sa_sb(t_order *list);
void		ss(t_order *list_a, t_order *list_b);
void		rotate(t_order *list_a, t_order *list_b);
t_order		*ra_rb(t_order *list);
t_order		*rra_rrb(t_order *list);
t_order		*push(t_order *org, t_order *dst);
void		reverse(t_order *list_a, t_order *list_b);



#endif
