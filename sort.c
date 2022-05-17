/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:29:19 by afaby             #+#    #+#             */
/*   Updated: 2022/05/17 18:28:56 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_ll *l)
{
	t_ll	*tmp;
	int		size;

	size = 0;
	tmp = l;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

void	sort(t_stack *a, t_stack *b)
{
	
}
