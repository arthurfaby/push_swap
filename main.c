/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:35:01 by afaby             #+#    #+#             */
/*   Updated: 2022/05/18 14:57:40 by afaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlst(t_ll *a, t_ll *b)
{
	t_ll	*tmpa;
	t_ll	*tmpb;

	tmpa = a;
	tmpb = b;
	ft_printf("----------------|----------------\n");
	ft_printf("|    STACK A    |    STACK B    |\n");
	ft_printf("----------------|----------------\n");
	while (tmpa || tmpb)
	{
		if (tmpa)
		{	
			if (tmpa->data > 9999999 || tmpa->data < -999999)
				ft_printf("%d\t|", tmpa->data);
			else
				ft_printf("%d\t\t|", tmpa->data);
			tmpa = tmpa->next;
		}
		else
			ft_printf("\t\t|");
		if (tmpb)
		{
			ft_printf("%d\n", tmpb->data);
			tmpb = tmpb->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("----------------|----------------\n");
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (ft_printf("%s (\"args\" or <args>)\n", argv[0])); // NOT ENOUGH ARGS
	if (argc == 2)
	{
		//if (check_one_arg(argv[1]))
		a.first = parse_stack_one_argument(argv[1]);
		//else
		//	return (0); //ERROR IN ARG
	}
	else
		a.first = parse_stack_multi_arguments(argc, argv);
	b.first = NULL;
	//printlst(a.first, b.first);
	sort(&a, &b);
	//printlst(a.first, b.first);
}
