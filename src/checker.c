/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:31:53 by nthomas-          #+#    #+#             */
/*   Updated: 2022/04/01 00:45:42 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_operations(char *str, t_data *data);
static void	read_instructions(t_data *data);

int	main(int argc, char *argv[])
{
	t_data	data;

	data.a = NULL;
	data.b = NULL;
	if (parse_input(argc, argv, &data) || verify_input(&data))
		error(&data);
	read_instructions(&data);
	if (validate(&data))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	stack_free(&data.a);
	stack_free(&data.b);
}

static void	read_instructions(t_data *data)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (find_operations(line, data))
			error(data);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}

static int	find_operations(char *str, t_data *data)
{
	if (!ft_strncmp(str, "sa\n", 3))
		sa(data, 1);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb(data, 1);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss(data);
	else if (!ft_strncmp(str, "pa\n", 3))
		pa(data);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb(data);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra(data, 1);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb(data, 1);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(data);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra(data, 1);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb(data, 1);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(data);
	else
		return (1);
	return (0);
}
