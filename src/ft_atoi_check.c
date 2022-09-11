/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:49:54 by nthomas-          #+#    #+#             */
/*   Updated: 2022/09/11 18:49:55 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long int	parse_str(const char *str, int *negative);

int	ft_atoi_check(const char *str, int *invalide)
{
	long		number;
	long int	i;
	int			flag;

	number = 0;
	flag = 1;
	i = parse_str(str, &flag);
	if (i < 0)
		return (0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number = (str[i] - '0') + (number * 10);
		i++;
	}
	if (!((number * flag) >= INT_MIN && (number * flag) <= INT_MAX))
		*invalide = 1;
	number *= flag;
	return (number);
}

static long int	parse_str(const char *str, int *negative)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (flag == 0 && ft_isspace(str[i]))
			;
		else if (flag == 0 && (str[i] == '-' || str[i] == '+'))
		{
			if (str[i] == '-')
				*negative = -1;
			flag = 1;
		}
		else if (!(str[i] >= '0' && str[i] <= '9'))
		{
			i = -1;
			break ;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			break ;
		i++;
	}
	return (i);
}
