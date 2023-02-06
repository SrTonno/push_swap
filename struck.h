/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struck.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:36:55 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/06 16:41:31 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCK_H
# define STRUCK_H

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
#endif
