/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:53:10 by afaby             #+#    #+#             */
/*   Updated: 2022/05/25 16:56:55 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, t_ops *ops, int add)
{
	t_ll	*tmp;
	t_ll	*tmp2;

	tmp = a->first;
	a->first = a->first->next;
	tmp2 = a->first;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	if (add)
		opsaddback(&ops, opnew("ra"));
}

void	rb(t_stack *b, t_ops *ops, int add)
{
	t_ll	*tmp;
	t_ll	*tmp2;

	tmp = b->first;
	b->first = b->first->next;
	tmp2 = b->first;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	if (add)
		opsaddback(&ops, opnew("rb"));
}

void	rr(t_stack *a, t_stack *b, t_ops *ops)
{
	ra(a, ops, 0);
	rb(b, ops, 0);
	opsaddback(&ops, opnew("rr"));
}
