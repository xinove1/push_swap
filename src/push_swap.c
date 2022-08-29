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
	if (parse_input(argc, argv, &data) || verify_input(&data))
	{
		ft_printf("AAAAAAAAAaaa\n");
		error(&data);
	}

	print_stacks(&data);
	pb(&data);
	rrb(&data, 1);
	print_stacks(&data);

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
