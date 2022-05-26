/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:51:55 by afaby             #+#    #+#             */
/*   Updated: 2022/05/24 11:17:17 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *s)
{
	t_ll	*tmp;
	int		min;

	min = s->first->data;
	tmp = s->first;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max(t_stack *s)
{
	t_ll	*tmp;
	int		max;

	max = s->first->data;
	tmp = s->first;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

void	sort_three(t_stack *a, t_ops *ops)
{
	int		min;
	int		max;

	min = get_min(a);
	max = get_max(a);
	if (a->first->next->next->data != max)
	{
		if (a->first->data == max)
			ra(a, ops, 1);
		else
			rra(a, ops, 1);
	}
	if (a->first->data != min)
		sa(a, ops, 1);
}

void	sort_four(t_stack *a, t_stack *b, t_ops *ops)
{
	int	min;

	min = get_min(a);
	if (a->first->next->data == min)
		ra(a, ops, 1);
	else if (a->first->next->next->data == min)
	{
		ra(a, ops, 1);
		ra(a, ops, 1);
	}
	else if (a->first->next->next->next->data == min)
		rra(a, ops, 1);
	pb(a, b, ops);
	sort_three(a, ops);
	pa(a, b, ops);
}

void	sort_five(t_stack *a, t_stack *b, t_ops *ops)
{
	int	min;

	min = get_min(a);
	if (a->first->next->data == min)
		ra(a, ops, 1);
	else if (a->first->next->next->data == min)
	{
		ra(a, ops, 1);
		ra(a, ops, 1);
	}
	else if (a->first->next->next->next->data == min)
	{
		rra(a, ops, 1);
		rra(a, ops, 1);
	}
	else if (a->first->next->next->next->next->data == min)
		rra(a, ops, 1);
	pb(a, b, ops);
	sort_four(a, b, ops);
	pa(a, b, ops);
}
