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
	int		stack_sz;

	data.a = NULL;
	data.b = NULL;
	if (argc == 1)
		exit(0);
	if (parse_input(argc, argv, &data) || verify_duplication(&data))
		error(&data);
	if (validate(&data))
	{
		stack_sz = stack_size(data.a);
		if (stack_sz == 3)
			sort_three(&data);
		else if (stack_sz == 5)
			sort_five(&data);
		else if (stack_sz > 5)
		{
			prep_stack(&data);
			radix(&data);
		}
	}
	print_stacks(&data);
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
