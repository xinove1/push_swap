/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:32:02 by nthomas-          #+#    #+#             */
/*   Updated: 2022/03/28 15:32:15 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data, int print)
{
	t_stack	*a;
	t_stack	*tmp;

	if (print)
		ft_printf("sa\n");
	if (!data->a || !data->a->next)
		return ;
	a = data->a;
	tmp = a->next;
	a->next = tmp->next;
	tmp->next = a;
	data->a = tmp;
}

void	sb(t_data *data, int print)
{
	t_stack	*b;
	t_stack	*tmp;

	if (print)
		ft_printf("sb\n");
	if (!data->b || !data->b->next)
		return ;
	b = data->b;
	tmp = b->next;
	b->next = tmp->next;
	tmp->next = b;
	data->b = tmp;
}

void	ss(t_data *data)
{
	ft_printf("ss\n");
	sa(data, 0);
	sb(data, 0);
}

void	pa(t_data *data)
{
	t_stack	*b;

	ft_printf("pa\n");
	if (!data->b)
		return ;
	b = data->b;
	data->b = data->b->next;
	b->next = data->a;
	data->a = b;
}

void	pb(t_data *data)
{
	t_stack	*a;

	ft_printf("pb\n");
	if (!data->a)
		return ;
	a = data->a;
	data->a = data->a->next;
	a->next = data->b;
	data->b = a;
}
