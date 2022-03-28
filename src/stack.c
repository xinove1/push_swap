/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:32:32 by nthomas-          #+#    #+#             */
/*   Updated: 2022/03/28 15:32:35 by nthomas-         ###   ########.fr       */
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

t_stack	*stack_penultimate(t_stack *stack)
{
	t_stack	*i;

	if (!stack)
		return (NULL);
	i = stack;
	if (!i->next)
		return (i);
	while (i->next->next)
		i = i->next;
	return (i);
}
