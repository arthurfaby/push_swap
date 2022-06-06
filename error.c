/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:47:49 by afaby             #+#    #+#             */
/*   Updated: 2022/06/06 09:35:40 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_arg(char *str)
{
	int		i;
	long	n;

	i = 0;
	if (*str == 0)
		return (0);
	if (ft_strlen(str) > 11)
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	n = ft_atol(str);
	if (n > 2147483647 || n < -2147483648)
		return (0);
	return (1);
}

int	check_one_argument(char *arg)
{
	char	**args;
	int		i;

	i = 0;
	if (!arg || !*arg)
		return (0);
	args = ft_split(arg, ' ');
	while (args[i])
	{
		if (!valid_arg(args[i]))
		{
			ft_free_double_pointer((void **)args);
			return (0);
		}
		i++;
	}
	ft_free_double_pointer((void **)args);
	return (1);
}

int	check_multi_arguments(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!valid_arg(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(t_stack *a)
{
	t_ll	*tmp;
	t_ll	*tmp2;

	tmp = a->first;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->data == tmp2->data)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}
