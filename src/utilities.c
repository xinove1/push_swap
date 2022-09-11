/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:58:01 by nthomas-          #+#    #+#             */
/*   Updated: 2022/09/11 19:01:55 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2darray(char **array)
{
	int		i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	error(t_data *data)
{
	stack_free(&data->a);
	stack_free(&data->b);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

int	validate(t_data *data)
{
	t_stack	*a;
	int		tmp;

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

void	ra(t_data *data, int print)
{
	t_stack	*a;
	t_stack	*tmp;

	if (print)
		ft_printf("ra\n");
	if (!data->a)
		return ;
	a = data->a;
	data->a = a->next;
	a->next = NULL;
	tmp = stack_last(data->a);
	if (tmp)
		tmp->next = a;
}
