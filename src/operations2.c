#include "push_swap.h"

void	rb(t_data *data, int print)
{
	t_stack	*b;
	t_stack	*tmp;

	if (print)
		ft_printf("rb\n");
	if (!data->b)
		return ;
	b = data->b;
	data->b = b->next;
	b->next = NULL;
	tmp = stack_last(data->b);
	if (tmp)
		tmp->next = b;
}

void	rr(t_data *data)
{
	ft_printf("rr\n");
	ra(data, 0);
	rb(data, 0);
}

void	rra(t_data *data, int print)
{
	t_stack	*last;
	t_stack	*penul;

	if (print)
		ft_printf("rra\n");
	if (!data->a)
		return ;
	last = stack_last(data->a);
	penul = stack_penultimate(data->a);
	if (!last || !penul)
		return ;
	last->next = data->a;
	data->a = last;
	penul->next = NULL;
}

void	rrb(t_data *data, int print)
{
	t_stack	*last;
	t_stack	*penul;

	if (print)
		ft_printf("rrb\n");
	if (!data->b)
		return ;
	last = stack_last(data->b);
	penul = stack_penultimate(data->b);
	if (!last || !penul)
		return ;
	last->next = data->b;
	data->b = last;
	penul->next = NULL;
}

void	rrr(t_data *data)
{
	ft_printf("rrr\n");
	rra(data, 0);
	rrb(data, 0);
}
