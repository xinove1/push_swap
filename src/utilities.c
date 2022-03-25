/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:58:01 by nthomas-          #+#    #+#             */
/*   Updated: 2022/03/25 14:58:01 by nthomas-         ###   ########.fr       */
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

void	init_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->stack_size = 0;
	data->algo = 0;
}

void	error(t_data *data)
{
	stack_free(&data->a);
	stack_free(&data->b);
	ft_putstr_fd("Error\n", 1);
	exit(1);
}
