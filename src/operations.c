#include "push_swap.h"

/* sa (swap a): Swap the first 2 elements at the top of stack a. */
/* Do nothing if there is only one or no elements. */
void	sa(t_data *data)
{
	t_stack	*a;
	t_stack	*tmp;

	ft_printf("sa\n");
	a = data->a;
	tmp = a->next;
	if (!a || !a->next)
		return ;
	a->next = tmp->next;
	tmp->next = a;
	data->a = tmp;
}

/* sb (swap b): Swap the first 2 elements at the top of stack b. */
/* Do nothing if there is only one or no elements. */
void	sb(t_data *data)
{
	t_stack	*b;
	t_stack	*tmp;

	ft_printf("sb\n");
	b = data->b;
	tmp = b->next;
	if (!b || !b->next)
		return ;
	b->next = tmp->next;
	tmp->next = b;
	data->b = tmp;
}

// ss : sa and sb at the same time.
void	ss(t_data *data)
{
	ft_printf("ss\n");
	sa(data);
	sb(data);
}

/* pa (push a): Take the first element at the top of b and put it at the top of a. */
/* Do nothing if b is empty. */
void	pa(t_data *data)
{
	t_stack	*b;

	ft_printf("pa\n");
	if (!data->b)
		return ;
	b = data->b;
	data->b = data->b->next;
	b->next = data->a;
	data->a = b;
}

/* pb (push b): Take the first element at the top of a and put it at the top of b. */
/* Do nothing if a is empty. */
void	pb(t_data *data)
{
	t_stack	*a;

	ft_printf("pb\n");
	if (!data->a)
		return ;
	a = data->a;
	data->a = data->a->next;
	a->next = data->b;
	data->b = a;
}

/* ra (rotate a): Shift up all elements of stack a by 1. */
/* The first element becomes the last one. */
void	ra(t_data *data)
{
	t_stack	*a;
	t_stack	*tmp;

	ft_printf("ra\n");
	a = data->a;
	data->a = a->next;
	a->next = NULL;
	tmp = stack_last(data->a);
	tmp->next = a;
}

/* rb (rotate b): Shift up all elements of stack b by 1. */
/* The first element becomes the last one. */
void	rb(t_data *data)
{
	t_stack	*b;
	t_stack	*tmp;

	ft_printf("rb\n");
	b = data->b;
	data->b = b->next;
	b->next = NULL;
	tmp = stack_last(data->b);
	tmp->next = b;
}

// rr : ra and rb at the same time.
void	rr(t_data *data)
{
	ft_printf("rr\n");
	ra(data);
	rb(data);
}

/* rra (reverse rotate a): Shift down all elements of stack a by 1. */
/* The last element becomes the first one. */
void	rra(t_data *data)
{
	t_stack	*last;
	t_stack	*penul;

	ft_printf("rra\n");
	last = stack_last(data->a);
	penul = stack_penultimate(data->a);
	last->next = data->a;
	data->a = last;
	penul->next = NULL;
}

/* rrb (reverse rotate b): Shift down all elements of stack b by 1. */
/* The last element becomes the first one. */
void	rrb(t_data *data)
{
	t_stack	*last;
	t_stack	*penul;

	ft_printf("rra\n");
	last = stack_last(data->b);
	penul = stack_penultimate(data->b);
	last->next = data->b;
	data->b = last;
	penul->next = NULL;
}

// rrr : rra and rrb at the same time.
void	rrr(t_data *data)
{
	ft_printf("rrr\n");
	rra(data);
	rrb(data);
}
