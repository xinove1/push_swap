/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:57:57 by nthomas-          #+#    #+#             */
/*   Updated: 2022/09/11 19:01:46 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	stack = NULL;
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
