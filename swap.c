/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:53:53 by afaby             #+#    #+#             */
/*   Updated: 2022/05/17 16:51:59 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	t_ll	*tmp;

	tmp = a->first;
	a->first = a->first->next;
	tmp->next = a->first->next;
	a->first->next = tmp;
}

void	sb(t_stack *b)
{
	t_ll	*tmp;

	tmp = b->first;
	b->first = b->first->next;
	tmp->next = b->first->next;
	b->first->next = tmp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
