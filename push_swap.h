/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:42:37 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/02 16:47:42 by tvillare         ###   ########.fr       */
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
	int				index;
	struct s_order	*next;
	struct s_order	*back;
}				t_order;

typedef struct s_header
{
	struct s_order	*first;
}				t_header;

typedef struct s_print
{
	int				id;
	struct s_print	*next;
}				t_print;

////Funtions
t_order		*create_list(char **raw, t_order *list_a);
t_order		*create_new_block(t_order *list_a, int out, int position);
void		free_map(char **map);
/// Operaciones
t_order		*ft_sa(t_order *list_a, t_print *mob);
t_order		*ft_sb(t_order *list_b, t_print *mob);
void		ft_ss(t_order *list_a, t_order *list_b);
t_order		*ft_rra(t_order *list_a, t_print *mob);
t_order		*ft_rrb(t_order *list_b, t_print *mob);
void		ft_rrr(t_order *list_a, t_order *list_b);
t_order		*ft_ra(t_order *list_a, t_print *mob);
t_order		*ft_rb(t_order *list_b, t_print *mob);
void		ft_rr(t_order *list_a, t_order *list_b);
void		ft_pa(t_order *list_b, t_order *list_a, t_print *mob);
void		ft_pb(t_order *list_a, t_order *list_b, t_print *mob);

/// utils struct
int			ft_struclen(t_order *list);
t_order		*find_end_list(t_order *list_a);
t_print		*find_first_print(t_print *mob);
t_order		*find_first_list(t_order *list);
int			check_uniq_number(t_order *list, int num);
int			check_order_struck_asd(t_order *list);
int			check_order_struck_dst(t_order *list);
int			find_min_value(t_order *list);
t_order		*push_min_to_b(t_order *list_a, t_order *list_b, t_print *mob);
void		created_index(t_order *list, int len);
t_order		*move_block_b(t_order *list_a, t_order *list_b, int limits[2], t_print *mob);
int			find_max_value(t_order *list);
//void		return_to_a(t_order *list_a, t_order *list_b, int count);
t_order		*min_to_top (t_order *list, int max, t_print *mob);
int			top_or_under(t_order *list, int num);
void		struct_free(t_order *list, t_print *mob);

t_order		*psorder(t_order *list, int max, t_print *mob);
void		total_return(t_order *org, t_order *dst, int top, t_print *mob);
t_print		*find_list_print(t_print *mob);

void		print_list(t_print *mob);
t_order		*move_top_a(t_order *list_a, int limits[2], int mode, t_print *mob);

int			search_top_or_under(t_order *list, int min, int max, int len);

void		add_block_mob(t_print *mob, int type);
//Argoridmos
void		two_list(t_order *list_a, t_print *mob);
void		small_list(t_order *list_a, t_print *mob);
t_order		*five_number(t_order *list_a, t_print *mob);
t_order		*hundred_number(t_order *list_a, t_print *mob);
t_order		*max_number(t_order *list_a, t_print *mob);


void	radix(t_order *list_a, t_print *mob);



void print_cosas(t_order *list_a);

#endif
