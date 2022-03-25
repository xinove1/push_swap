/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:58:50 by nthomas-          #+#    #+#             */
/*   Updated: 2022/03/25 14:49:54 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	init_data(&data);
	if (parse_input(argc, argv, &data) || verify_input(&data))
		error(&data);
	print_stacks(&data);
	stack_free(&data.a);
	stack_free(&data.b);
}

void	print_stacks(t_data *data)
{
	t_stack	*a;
	t_stack	*b;

	a = data->a;
	b = data->b;
	ft_printf("a: ");
	while (a)
	{
		ft_printf("%d, ", a->value);
		a = a->next;
	}
	ft_printf("\nb: ");
	while (b)
	{
		ft_printf("%d, ", b->value);
		b = b->next;
	}
	ft_printf("\n");
}
