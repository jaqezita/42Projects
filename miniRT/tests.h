/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:48:14 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/04 19:07:20 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <stdlib.h>
# include <assert.h>

# define EPSILON 0.00001

typedef struct	s_tuple
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_tuple;

t_tuple		create_tuple(double x, double y, double z, double w);
t_tuple		create_point(double x, double y, double z);
t_tuple		create_vector(double x, double y, double z);
t_tuple		add_tuples(t_tuple a, t_tuple b);
t_tuple		subtract_tuples(t_tuple a, t_tuple b);
t_tuple		deny_tuples(t_tuple a);
t_tuple		multiply_tuples(t_tuple a, double number);
t_tuple		divide_tuple(t_tuple a, double number);
bool		check_tuple_equality(t_tuple a, t_tuple b);
double		vector_magnitude(t_tuple a);
t_tuple		vector_norm(t_tuple a);
double		dot_product(t_tuple a, t_tuple b);
t_tuple		cross_product(t_tuple a, t_tuple b);




# endif