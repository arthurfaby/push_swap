/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:53:10 by afaby             #+#    #+#             */
/*   Updated: 2022/05/17 17:28:28 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
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
	ft_printf("ra\n");
}

void	rb(t_stack *b)
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
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}
