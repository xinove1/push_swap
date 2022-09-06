/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:58:50 by nthomas-          #+#    #+#             */
/*   Updated: 2022/03/28 15:32:19 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit_test(int c);

int	main(int argc, char *argv[])
{
	t_data	data;

	init_data(&data);
	//TODO check pdf for min number of entrys
	if (argc == 1 || parse_input(argc, argv, &data) || verify_input(&data))
	{
		ft_printf("AAAAAAAAAaaa\n");
		error(&data);
	}

	//TODO check if is already sorted

	print_stacks(&data);
	if (validate(&data))
	{
		prep_stack(&data);
		print_stacks(&data);
		radix(&data);
		print_stacks(&data);
	}

	//Cleaning
	stack_free(&data.a);
	stack_free(&data.b);
}

int	ft_isdigit_test(int c)
{
	ft_printf("c: %d\n", c);
	if (c >= '0' && c <= '9')
	{
		ft_printf("is digit\n");
		return (1);
	}
	ft_printf("is not digit\n");
	return (0);
}

int	validate(t_data *data)
{
	t_stack	*a;
	int		tmp;

	if (data->b)
		return (1);
	a = data->a;
	tmp = a->value;
	a = a->next;
	while (a)
	{
		if (a->value < tmp)
			return (1);
		tmp = a->value;
		a = a->next;
	}
	return (0);
}
