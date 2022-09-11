/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:59:08 by nthomas-          #+#    #+#             */
/*   Updated: 2022/09/11 19:01:43 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# define INT_MIN 	-2147483648
# define INT_MAX 	+2147483647

typedef struct s_stack
{
	int						value;
	struct s_stack			*next;
}	t_stack;

typedef struct s_data
{
	t_stack					*a;
	t_stack					*b;
}	t_data;

int			parse_input(int argc, char *argv[], t_data *data);
int			parse_input_str(char *str, t_data *data);
int			verify_duplication(t_data *data);
void		free_2darray(char **array);
void		error(t_data *data);
void		stack_add_back(t_stack **stack, t_stack *n);
t_stack		*stack_last(t_stack *stack);
int			stack_size(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_free(t_stack **stack);
void		print_stacks(t_data *data);
t_stack		*stack_penultimate(t_stack *stack);
void		prep_stack(t_data *data);
void		radix(t_data *data);
void		sort_three(t_data *data);
void		sort_four(t_data *data);
void		sort_five(t_data *data);
int			validate(t_data *data);
int			ft_atoi_check(const char *str, int *invalide);
void		sa(t_data *data, int print);
void		sb(t_data *data, int print);
void		ss(t_data *data, int print);
void		pa(t_data *data, int print);
void		pb(t_data *data, int print);
void		ra(t_data *data, int print);
void		rb(t_data *data, int print);
void		rr(t_data *data, int print);
void		rra(t_data *data, int print);
void		rrb(t_data *data, int print);
void		rrr(t_data *data, int print);

#endif
