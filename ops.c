/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:06:35 by afaby             #+#    #+#             */
/*   Updated: 2022/05/25 16:28:18 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_pattern(t_ops *ops, char *s1, char *s2)
{
	t_ops	*tmp;

	tmp = ops;
	if (tmp)
	{
		if (tmp->next)
		{
			if (tmp->next->next)
			{
				if (ft_strncmp(tmp->next->data, s1, 3) == 0)
				{
					if (ft_strncmp(tmp->next->next->data, s2, 3) == 0)
						return (1);
				}
				else if (ft_strncmp(tmp->next->data, s2, 3) == 0)
					if (ft_strncmp(tmp->next->next->data, s1, 3) == 0)
						return (1);
			}
		}
	}
	return (0);
}

void	insert_el(char *data, t_ops *ops, t_ops *tmp)
{
	t_ops	*new;
	t_ops	*old;

	new = opnew(data);
	old = tmp->next;
	new->next = tmp->next->next->next;
	tmp->next = new;
	free(old->next);
	free(old);
	tmp = ops;
}

void	opti_ops(t_ops *ops)
{
	t_ops	*tmp;
	t_ops	*old;

	tmp = ops;
	while (tmp)
	{
		if (check_pattern(tmp, "pa", "pb") || check_pattern(tmp, "ra", "rra"))
		{
			old = tmp->next;
			tmp->next = tmp->next->next->next;
			free(old->next);
			free(old);
			tmp = ops;
		}
		else if (check_pattern(tmp, "ra", "rb"))
			insert_el("rr", ops, tmp);
		else
			tmp = tmp->next;
	}
}

void	opsaddback(t_ops **lst, t_ops *new)
{
	t_ops	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_ops	*opnew(char *data)
{
	t_ops	*op;

	op = malloc(sizeof(t_ops));
	if (!op)
		return (0);
	op->next = NULL;
	op->data = data;
	return (op);
}
