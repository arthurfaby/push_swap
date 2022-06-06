/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:35:01 by afaby             #+#    #+#             */
/*   Updated: 2022/06/06 10:45:19 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ops(t_ops *ops)
{
	while (ops)
	{
		if (*(ops->data) != '\0')
			ft_printf("%s\n", ops->data);
		ops = ops->next;
	}
}

void	run(t_stack *a, t_stack *b, t_ops *ops)
{
	int	len;

	b->first = NULL;
	ops->next = NULL;
	ops->data = "";
	if (is_sorted(a))
	{
		free_all(a, b, ops);
		return ;
	}
	len = lstsize(a);
	if (len == 2)
		sa(a, ops, 1);
	else if (len == 3)
		sort_three(a, ops);
	else if (len == 4)
		sort_four(a, b, ops);
	else if (len == 5)
		sort_five(a, b, ops);
	else
		sort(a, b, ops);
	opti_ops(ops);
	print_ops(ops);
	free_all(a, b, ops);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_ops	ops;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (check_one_argument(argv[1]))
			a.first = parse_stack_one_argument(argv[1]);
		else
			return (ft_printf("Error\n"));
	}
	else if (check_multi_arguments(argv))
		a.first = parse_stack_multi_arguments(argc, argv);
	else
		return (ft_printf("Error\n"));
	if (!check_duplicate(&a))
	{
		free_stack(a.first);
		return (ft_printf("Error\n"));
	}
	run(&a, &b, &ops);
	return (0);
}
