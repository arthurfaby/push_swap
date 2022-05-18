/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:29:19 by afaby             #+#    #+#             */
/*   Updated: 2022/05/18 13:31:11 by afaby            ###   ########.fr       */
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

int	find_max_value(t_stack *a)
{
	t_ll	*tmp;
	int		max;

	tmp = a->first;
	max = tmp->data;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

void	sort(t_stack *a, t_stack *b)
{
	int		n_bytes_max;
	int		max;
	int		i;
	int		j;
	int		len;
	t_ll	*tmp;

	i = 0;
	n_bytes_max = 0;
	max = find_max_value(a);
	len = lstsize(a);
	while (max >> n_bytes_max)
		n_bytes_max++;
	tmp = a->first;
	while (i < n_bytes_max)
	{
		j = 0;
		while (j < len && !is_empty(a))
		{
			if (tmp && (tmp->data >> i & 1) == 1)
				pb(a, b);
			else
				ra(a);
			tmp = a->first;
			j++;
		}
		while (!is_empty(b))
			pa(a, b);
		i++;
	}
}
