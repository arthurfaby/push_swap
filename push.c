/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:41:10 by afaby             #+#    #+#             */
/*   Updated: 2022/05/17 17:28:39 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_ll	*tmp;

	tmp = a->first;
	a->first = b->first;
	b->first = b->first->next;
	a->first->next = tmp;
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	t_ll	*tmp;

	tmp = b->first;
	b->first = a->first;
	a->first = a->first->next;
	b->first->next = tmp;
	ft_printf("pb\n");
}
