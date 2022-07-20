/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:57:48 by nthomas-          #+#    #+#             */
/*   Updated: 2022/03/28 15:32:16 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(int argc, char *argv[], t_data *data)
{
	int	i;
	int	j;
	int	parse;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		parse = 1;
		while (argv[i][++j])
		{
			if (ft_isspace(argv[i][j]))
			{
				if (parse_input_str(argv[i], data))
					return (1);
				parse = 0;
				break;
			}
			else if (!(ft_isdigit(argv[i][j])) && argv[i][j] != '-')
				return (1);
		}
		if (parse)
			stack_add_back(&data->a, stack_new(atoi(argv[i])));
	}
	return (0);
}

//FIXME Most probaly slow with big list of numbers
int	verify_input(t_data *data)
{
	t_stack	*i;
	t_stack	*x;

	i = data->a;
	while (i)
	{
		x = data->a;
		while (x)
		{
			if (i->value == x->value && i != x)
				return (1);
			x = x->next;
		}
		i = i->next;
	}
	return (0);
}

int	parse_input_str(char *str, t_data *data)
{
	char	**parsed;
	int		i;
	int		x;
	int		parse;

	parsed = ft_split(str, ' ');
	i = -1;
	while (parsed[++i])
	{
		x = 0;
		parse = 1;
		while (parsed[i][x])
		{
			if (!(ft_isdigit(parsed[i][x])))
			{
				free_2darray(parsed);
				return (1);
			}
			x++;
		}
		if (parse)
			stack_add_back(&data->a, stack_new(atoi(parsed[i])));
	}
	free_2darray(parsed);
	return (0);
}
