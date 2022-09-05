/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas </var/spool/mail/thomas>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:33:10 by thomas            #+#    #+#             */
/*   Updated: 2022/07/25 13:33:10 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void	copy_to_array(t_stack *a, int	*stack);
static void selection_sort(int *arr, int n);
static int	find_pos(int value,  int *sorted_stack, int sz);

void	prep_stack(t_data *data)
{
	int		sz;
	int		*sorted_stack;
	t_stack	*tmp;

	sz = stack_size(data->a);
	sorted_stack = malloc(sizeof(int) * sz);
	copy_to_array(data->a, sorted_stack);
	selection_sort(sorted_stack, sz);
	tmp = data->a;
	while (tmp)
	{
		tmp->value = find_pos(tmp->value, sorted_stack, sz);
		tmp = tmp->next;
	}
	free(sorted_stack);
}

static void	copy_to_array(t_stack *a, int	*stack)
{
	int	i;

	i = 0;
	while (a)
	{
		stack[i] = a->value;
		i++;
		a = a->next;
	}
}

static void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


//TODO isso
static void selection_sort(int *arr, int sz)
{
    int i, j, min;

	i = 0;
    while (i < sz - 1)
	{
        min = i;
		j = i + 1;
		while (j < sz)
		{
            if (arr[j] < arr[min])
                min = j;
			j++;
		}
        swap(&arr[min], &arr[i]);
		i++;
    }
}

static int	find_pos(int value,  int *sorted_stack, int sz)
{
	int	i;

	i = 0;
	while (i < sz)
	{
		if (sorted_stack[i] == value)
			break ;
		i++;
	}
	return (i);
}

