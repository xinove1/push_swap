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
			if (((data->a->value >> i)&1) == 1)
				ra(data, 1);
			else
				pb(data);
		}
		while (data->b)
			pa(data);
		if (!validate(data))
			break ;
	}
}
