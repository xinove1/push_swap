/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:01:29 by nthomas-          #+#    #+#             */
/*   Updated: 2022/09/11 19:01:30 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_data *data)
{
	int	i;
	int	j;
	int	a_sz;
	int	bit_max;

	bit_max = 0;
	a_sz = stack_size(data->a);
	while (((a_sz - 1) >> bit_max) != 0)
		++bit_max;
	i = -1;
	while (++i < bit_max)
	{
		j = -1;
		while (++j < a_sz)
		{
			if (((data->a->value >> i) & 1) == 1)
				ra(data, 1);
			else
				pb(data, 1);
		}
		while (data->b)
			pa(data, 1);
		if (!validate(data))
			break ;
	}
}

void	sort_three(t_data *data)
{
	int	top;
	int	mid;
	int	bot;

	top = data->a->value;
	mid = data->a->next->value;
	bot = data->a->next->next->value;
	if (!validate(data))
		return ;
	if (top > mid && top < bot && mid < bot)
		sa(data, 1);
	else if (top > mid && top > bot && mid > bot)
	{
		sa(data, 1);
		rra(data, 1);
	}
	else if (top > mid && top > bot && mid < bot)
		ra(data, 1);
	else if (top < mid && top < bot && mid > bot)
	{
		sa(data, 1);
		ra(data, 1);
	}
	else
		rra(data, 1);
}

static void	sort_five_aux(t_data *d, int top, int mid, int bot)
{
	int	topp;

	topp = d->b->value;
	if (topp > d->a->value && topp > top && topp < mid)
	{
		ra(d, 1);
		pa(d, 1);
		sa(d, 1);
		rra(d, 1);
		return ;
	}
	pa(d, 1);
	if (topp > d->a->next->value && topp < top)
		sa(d, 1);
	else if (topp > d->a->next->value && topp > top && topp > mid && topp < bot)
	{
		rra(d, 1);
		sa(d, 1);
		ra(d, 1);
		ra(d, 1);
	}
	else if (topp > d->a->next->value && topp > top && topp > mid && topp > bot)
		ra(d, 1);
}

void	sort_five(t_data *data)
{
	int	top;
	int	mid;
	int	bot;

	if (data->a->value + data->a->next->value == 5)
		rra(data, 1);
	pb(data, 1);
	sort_four(data);
	top = data->a->next->value;
	mid = data->a->next->next->value;
	bot = data->a->next->next->next->value;
	sort_five_aux(data, top, mid, bot);
}

void	sort_four(t_data *data)
{
	int	topp;
	int	top;
	int	mid;
	int	bot;

	pb(data, 1);
	sort_three(data);
	top = data->a->value;
	mid = data->a->next->value;
	bot = data->a->next->next->value;
	pa(data, 1);
	topp = data->a->value;
	if (topp > top && topp > mid && topp > bot)
		ra(data, 1);
	else if (topp > top && topp < mid)
		sa(data, 1);
	else if (topp > top && topp > mid && topp < bot)
	{
		rra(data, 1);
		sa(data, 1);
		ra(data, 1);
		ra(data, 1);
	}
}
