/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:35:01 by afaby             #+#    #+#             */
/*   Updated: 2022/05/13 17:51:50 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		return (0); // NOT ENOUGH ARGS
	if (argc == 2)
	{
		if (check_one_arg(argv[1]))
			a = parse_stack_one_argument(argv[1]);
		else
			return (0); //ERROR IN ARG
	}
	else
		//a = parse_stack_multi_arguments(argv);
		return (0); // TEMP RETURN
	b = create_b_stack();
	(void)a;
	(void)b;
}
