/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:13:52 by jaqribei          #+#    #+#             */
/*   Updated: 2023/11/04 05:16:46 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

void	check_errors(int argc, char *argv[]);
void	print_stack(t_list **stack_a);
void	push_a(t_list *stack_a, t_list *stack_b);
void	push_b(t_list *stack_a, t_list *stack_b);
void	swap_a(t_list *stack_a);
void	swap_b(t_list *stack_a, t_list *stack_b);
void	swap_ss(t_list *stack_a, t_list *stack_b);
void	rotate_a(t_list *stack_a, t_list *stack_b);
void	rotate_b(t_list *stack_a, t_list *stack_b);
void	rotate_rr(t_list *stack_a, t_list *stack_b);
void	reverse_rotate_a(t_list *stack_a, t_list *stack_b);
void	reverse_rotate_b(t_list *stack_a, t_list *stack_b);
void	reverse_rotate_rrr(t_list *stack_a, t_list *stack_b);

#endif