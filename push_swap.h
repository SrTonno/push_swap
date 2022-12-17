/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:42:37 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/17 18:09:01 by tvillare         ###   ########.fr       */
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
t_order		*create_list(char **raw, t_order *list_a);
t_order		*create_new_block(t_order *list_a, int out, int position);
void		free_map(char **map);
/// Operaciones
t_order		*ft_sa(t_order *list_a);
t_order		*ft_sb(t_order *list_b);
void		ft_ss(t_order *list_a, t_order *list_b);
t_order		*ft_rra(t_order *list_a);
t_order		*ft_rrb(t_order *list_b);
void		ft_rrr(t_order *list_a, t_order *list_b);
t_order		*ft_ra(t_order *list_a);
t_order		*ft_rb(t_order *list_b);
void		ft_rr(t_order *list_a, t_order *list_b);
void		ft_pa(t_order *list_b, t_order *list_a);
void		ft_pb(t_order *list_b, t_order *list_a);

/// utils struct
int			ft_struclen(t_order *list);
t_order		*find_end_list(t_order *list_a);
t_order		*find_first_list(t_order *list);
t_order		*to_next(t_order *list_a, int out, int position);
int			check_uniq_number(t_order *list, int num);
int			check_order_struck_asd(t_order *list);
int			check_order_struck_dst(t_order *list);
int			find_min_value(t_order *list);
t_order		*push_min_to_b(t_order *list_a, t_order *list_b);
//Argoridmos
void		small_list(t_order *list_a);
t_order		*five_number(t_order *list_a);

#endif
