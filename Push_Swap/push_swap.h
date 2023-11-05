/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:13:52 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/04 20:56:12 by jaqribei         ###   ########.fr       */
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

void	check_errors(int argc, char *argv[]);
void	print_stack(t_node **stack_a);
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
void	check_argument_errors(int argc, char *argv[]);
t_node	*populate_stack(int argc, char *argv[]);
void	ft_clear(t_node **lst, void (*del)(void *));
int		ft_size(t_node *lst);
t_node	*ft_last(t_node *lst);
void	ft_add_back(t_node **lst, t_node *new);
t_node	*ft_new(void *content);

#endif