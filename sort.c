/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:29:19 by afaby             #+#    #+#             */
/*   Updated: 2022/05/26 10:02:09 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_value(t_stack *a)
{
	t_ll	*tmp;
	int		n;

	tmp = a->first;
	n = tmp->data;
	while (tmp)
	{
		if (tmp->data > n)
			n = tmp->data;
		tmp = tmp->next;
	}
	return (n);
}

int	do_r(t_stack *a, int len, int i, int equality)
{
	int		cpt;
	int		distance_ra;
	int		distance_rra;
	t_ll	*tmp;

	tmp = a->first;
	cpt = -1;
	distance_ra = -1;
	distance_rra = -1;
	while (++cpt < len && distance_ra == -1)
	{
		if ((tmp->data >> i & 1) == equality)
			distance_ra = cpt;
		tmp = tmp->next;
	}
	cpt = -1;
	tmp = a->first;
	while (++cpt < len)
	{
		if ((tmp->data >> i & 1) == equality)
			distance_rra = cpt;
		tmp = tmp->next;
	}
	return (distance_ra > distance_rra);
}

void	repush_a(t_stack *a, t_stack *b, int i, t_ops *ops)
{
	int	len;
	int	cpt;

	len = lstsize(b);
	cpt = 0;
	while (cpt < len)
	{
		if ((b->first->data >> i & 1) == 1)
			pa(a, b, ops);
		else
			rb(b, ops, 1);
		cpt++;
	}
}

void	sort(t_stack *a, t_stack *b, t_ops *ops)
{
	int		n_bytes_max;
	int		i;
	int		j;
	int		len;

	i = -1;
	n_bytes_max = get_max_bytes(a);
	while (++i < n_bytes_max)
	{
		j = -1;
		len = lstsize(a);
		while (++j < len)
		{
			if ((a->first->data >> i & 1) == 0)
				pb(a, b, ops);
			else
				ra(a, ops, 1);
		}
		if (i + 1 != n_bytes_max)
			repush_a(a, b, i + 1, ops);
	}
	while (!is_empty(b))
		pa(a, b, ops);
}
