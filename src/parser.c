/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:57:48 by nthomas-          #+#    #+#             */
/*   Updated: 2022/09/11 19:00:31 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_to_stack(t_data *data, char *str);

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
				break ;
			}
			else if (!(ft_isdigit(argv[i][j])) && argv[i][j] != '-')
				return (1);
		}
		if (parse && add_to_stack(data, argv[i]))
			return (1);
	}
	return (0);
}

static int	add_to_stack(t_data *data, char *str)
{
	int	flag;

	flag = 0;
	stack_add_back(&data->a, stack_new(ft_atoi_check(str, &flag)));
	if (flag)
		return (1);
	return (0);
}

int	verify_duplication(t_data *data)
{
	t_stack	*i;
	t_stack	*x;

	i = data->a;
	while (i)
	{
		x = i;
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
			stack_add_back(&data->a, stack_new(ft_atoi(parsed[i])));
	}
	free_2darray(parsed);
	return (0);
}
