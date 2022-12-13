/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:42:37 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/08 18:31:57 by tvillare         ###   ########.fr       */
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

#endif
