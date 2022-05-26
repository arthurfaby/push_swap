/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:08:46 by afaby             #+#    #+#             */
/*   Updated: 2022/05/25 16:55:11 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(t_ll *a, t_ll *tmp)
{
	int		pos;
	t_ll	*tmp2;

	pos = 0;
	tmp2 = a;
	while (tmp2)
	{
		if (tmp->data > tmp2->data)
			pos++;
		tmp2 = tmp2->next;
	}
	return (pos);
}

t_ll	*translate(t_ll *a)
{
	t_ll	*new_list;
	t_ll	*new_el;
	t_ll	*tmp;
	int		pos;

	tmp = a;
	new_list = NULL;
	while (tmp)
	{
		pos = get_pos(a, tmp);
		if (!new_list)
		{
			new_list = lstnew(pos);
			new_el = new_list;
		}
		else
		{
			new_el->next = lstnew(pos);
			new_el = new_el->next;
		}
		tmp = tmp->next;
	}
	free_stack(a);
	return (new_list);
}

t_ll	*parse_stack_one_argument(char *str)
{
	t_ll	*a;
	t_ll	*temp;
	char	**args;
	int		i;

	i = 0;
	args = ft_split(str, ' ');
	if (!args)
		return (0);
	a = lstnew(ft_atoi(args[i++]));
	temp = a;
	while (args[i])
	{
		temp->next = lstnew(ft_atoi(args[i]));
		temp = temp->next;
		i++;
	}
	ft_free_double_pointer((void **)args);
	a = translate(a);
	return (a);
}

t_ll	*parse_stack_multi_arguments(int n, char **argv)
{
	int		i;
	t_ll	*a;
	t_ll	*temp;

	i = 1;
	a = lstnew(ft_atoi(argv[i++]));
	temp = a;
	while (i < n)
	{
		temp->next = lstnew(ft_atoi(argv[i]));
		temp = temp->next;
		i++;
	}
	a = translate(a);
	return (a);
}
