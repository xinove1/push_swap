/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthomas- <nthomas-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:59:08 by nthomas-          #+#    #+#             */
/*   Updated: 2022/03/25 15:05:56 by nthomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_stack
{
	int							value;
	struct s_stack	*next;
}t_stack;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	int			stack_size;
	int			algo;
}t_data;

int			parse_input(int argc, char *argv[], t_data *data);
int			parse_input_str(char *str, t_data *data);
int			verify_input(t_data *data);

void		free_2darray(char **array);
void		init_data(t_data *data);
void		error(t_data *data);

void		stack_add_back(t_stack **stack, t_stack *n);
t_stack		*stack_last(t_stack *stack);
int			stack_size(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_free(t_stack **stack);
void		print_stacks(t_data *data);

#endif
