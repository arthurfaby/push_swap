/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:01:53 by afaby             #+#    #+#             */
/*   Updated: 2022/05/17 17:28:51 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
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
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
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
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
