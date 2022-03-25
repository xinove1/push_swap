/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:57:57 by nthomas-          #+#    #+#             */
/*   Updated: 2022/03/25 14:57:58 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

int	stack_size(t_stack *stack)
{
	int		i;
	t_stack	*j;

	i = 0;
	j = stack;
	while (j)
	{
		j = j->next;
		i++;
	}
	return (i);
}

void	stack_add_back(t_stack **stack, t_stack *n)
{
	t_stack	*i;

	if (!*stack)
		*stack = n;
	else
	{
		i = stack_last(*stack);
		i->next = n;
	}
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*i;

	if (!stack)
		return (NULL);
	i = stack;
	while (i->next)
		i = i->next;
	return (i);
}

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
