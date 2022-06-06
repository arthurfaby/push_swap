/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:40:22 by afaby             #+#    #+#             */
/*   Updated: 2022/06/05 11:27:18 by afaby            ###   ########.fr       */
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

typedef struct s_ops
{
	char			*data;
	struct s_ops	*next;
}	t_ops;

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

void	pa(t_stack *a, t_stack *b, t_ops *ops);
void	pb(t_stack *a, t_stack *b, t_ops *ops);

// SWAP.C

void	sa(t_stack *a, t_ops *ops, int add);
void	sb(t_stack *b, t_ops *ops, int add);
void	ss(t_stack *a, t_stack *b, t_ops *ops);

// ROTATE.C

void	ra(t_stack *a, t_ops *ops, int add);
void	rb(t_stack *b, t_ops *ops, int add);
void	rr(t_stack *a, t_stack *b, t_ops *ops);

// REVERSE_ROTATE.C

void	rra(t_stack *a, t_ops *ops, int add);
void	rrb(t_stack *b, t_ops *ops, int add);
void	rrr(t_stack *a, t_stack *b, t_ops *ops);

// SORT.C

void	sort(t_stack *a, t_stack *b, t_ops *ops);

// UTILS.C

int		is_empty(t_stack *s);
int		is_sorted(t_stack *s);
int		lstsize(t_stack *a);
int		find_max_value(t_stack *a);
int		get_max_bytes(t_stack *a);

// OPS.C

void	opsaddback(t_ops **list, t_ops *new);
t_ops	*opnew(char *data);
void	opti_ops(t_ops *ops);

// SORT_LITTLE.H

void	sort_three(t_stack *a, t_ops *ops);
void	sort_four(t_stack *a, t_stack *b, t_ops *ops);
void	sort_five(t_stack *a, t_stack *b, t_ops *ops);

// FREE.C

void	free_stack(t_ll *first);
void	free_all(t_stack *a, t_stack *b, t_ops *ops);

// ERROR.C

int		valid_arg(char *str);
int		check_one_argument(char *arg);
int		check_multi_arguments(char **argv);
int		check_duplicate(t_stack *a);

#endif
