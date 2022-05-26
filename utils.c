/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:16:49 by afaby             #+#    #+#             */
/*   Updated: 2022/05/25 17:07:48 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_stack *a)
{
	t_ll	*tmp;
	int		len;

	len = 0;
	tmp = a->first;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int	is_number(t_stack *s, int i, int b)
{
	t_ll	*tmp;

	tmp = s->first;
	while (tmp)
	{
		if ((tmp->data >> i & 1) == b)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	is_sorted(t_stack *s)
{
	t_ll	*tmp;

	tmp = s->first;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_empty(t_stack *s)
{
	if (s->first)
		return (0);
	return (1);
}

int	get_max_bytes(t_stack *a)
{
	int	max;
	int	n_bytes_max;

	max = find_max_value(a);
	n_bytes_max = 0;
	while (max >> n_bytes_max)
		n_bytes_max++;
	return (n_bytes_max);
}
