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

int	main(int argc, char *argv[])
{
	t_data	data;

	init_data(&data);
	if (parse_input(argc, argv, &data) || verify_input(&data))
		error(&data);
	print_stacks(&data);
	pb(&data);
	rrb(&data, 1);
	print_stacks(&data);
	print_stacks(&data);
	stack_free(&data.a);
	stack_free(&data.b);
}
