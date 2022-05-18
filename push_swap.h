/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:40:22 by afaby             #+#    #+#             */
/*   Updated: 2022/05/18 13:18:11 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_ll
{
	int			data;
	struct s_ll	*next;
}	t_ll;

typedef struct s_stack
{
	t_ll	*first;
}	t_stack;

// PARSE.C

t_ll	*parse_stack_one_argument(char *str);
t_ll	*parse_stack_multi_arguments(int n, char **argv);

// LST.C

t_ll	*lstnew(int data);

// PUSH.C

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// SWAP.C


void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// ROTATE.C

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

// REVERSE_ROTATE.C

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// SORT.C

int		lstsize(t_stack *a);
int		find_max_value(t_stack *a);
void	sort(t_stack *a, t_stack *b);

// UTILS.C

int		is_empty(t_stack *s);

#endif
