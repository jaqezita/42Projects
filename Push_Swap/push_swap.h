/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:13:52 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/10 22:42:05 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	unsigned int	index;
}					t_node;

void	check_duplicate_arguments(int argc, char *argv[]);
void	check_interger_overflow(int argc, char *argv[]);
void	check_argument_errors(int argc, char *argv[]);
void	error_check(int argc, char *argv[]);
void	print_stack(t_node **stack_a);
int		is_stack_sorted(t_node **stack_a);
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);
void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_ss(t_node **stack_a, t_node **stack_b);
void	rotate_a(t_node **stack_a);
void	rotate_b(t_node **stack_b);
void	rotate_rr(t_node **stack_a, t_node **stack_b);
void	reverse_rotate_a(t_node **stack_a);
void	reverse_rotate_b(t_node **stack_b);
void	reverse_rotate_rrr(t_node **stack_a, t_node **stack_b);
void	ft_clear(t_node **lst, void (*del)(void *));
void	ft_add_back(t_node **lst, t_node *new);
t_node	*populate_stack(int argc, char *argv[]);
t_node	*ft_last(t_node *lst);
t_node	*ft_new(int content);
int		ft_size(t_node *lst);
int		number_bits(int argc);
void	rank_nodes(t_node **stack_a);
void	radix_sort_binary(t_node **stack_a, t_node **stack_b, int bits);
void	push_back(t_node **stack_a, t_node **stack_b);
void	handle_two_number_stack(t_node **stack_a);
void	handle_three_number_stack(t_node **stack_a);
void	case_one(t_node **stack_a, int first, int middle, int last);
void	case_two(t_node **stack_a, int first, int middle, int last);

#endif