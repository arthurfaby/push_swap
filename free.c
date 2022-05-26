/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:42:13 by afaby             #+#    #+#             */
/*   Updated: 2022/05/25 16:56:00 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_ll *first)
{
	t_ll	*tmp;
	t_ll	*old;

	tmp = first;
	while (tmp)
	{
		old = tmp;
		tmp = tmp->next;
		free(old);
	}
}

void	free_ops(t_ops *ops)
{
	t_ops	*old;

	ops = ops->next;
	while (ops)
	{
		old = ops;
		ops = ops->next;
		free(old);
	}
}

void	free_all(t_stack *a, t_stack *b, t_ops *ops)
{
	free_stack(a->first);
	free_stack(b->first);
	free_ops(ops);
}
