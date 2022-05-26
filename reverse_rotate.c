/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:01:53 by afaby             #+#    #+#             */
/*   Updated: 2022/05/25 16:56:44 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, t_ops *ops, int add)
{
	t_ll	*tmp;
	t_ll	*tmp2;

	tmp = a->first;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp2->next = a->first;
	a->first = tmp2;
	tmp->next = NULL;
	if (add)
		opsaddback(&ops, opnew("rra"));
}

void	rrb(t_stack *b, t_ops *ops, int add)
{
	t_ll	*tmp;
	t_ll	*tmp2;

	tmp = b->first;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp2->next = b->first;
	b->first = tmp2;
	tmp->next = NULL;
	if (add)
		opsaddback(&ops, opnew("rrb"));
}

void	rrr(t_stack *a, t_stack *b, t_ops *ops)
{
	rra(a, ops, 0);
	rrb(b, ops, 0);
	opsaddback(&ops, opnew("rrr"));
}
