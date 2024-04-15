/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:48:14 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/15 17:46:44 by jaqribei         ###   ########.fr       */
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

typedef struct	s_matrix
{
	int			size;
	double		grid[4][4];
}				t_matrix;

t_tuple		create_tuple(double x, double y, double z, double w);
t_tuple		create_point(double x, double y, double z);
t_tuple		create_vector(double x, double y, double z);
t_tuple		add_tuples(t_tuple a, t_tuple b);
t_tuple		subtract_tuples(t_tuple a, t_tuple b);
t_tuple		deny_tuples(t_tuple a);
t_tuple		multiply_tuples_scalar(t_tuple a, double number);
t_tuple		divide_tuple_scalar(t_tuple a, double number);
int			check_tuple_equality(t_tuple a, t_tuple b);
double		vector_magnitude(t_tuple a);
t_tuple		vector_norm(t_tuple a);
double		dot_product(t_tuple a, t_tuple b);
t_tuple		cross_product(t_tuple a, t_tuple b);
t_matrix	create_matrix(int size, double numbers[]);
void		free_matrix(t_matrix m);
int			matrix_equality(t_matrix a, t_matrix b);
t_matrix	multiply_matrices(t_matrix a, t_matrix b);
t_tuple		multiply_matrix_by_tuple(t_matrix m, t_tuple p);
t_matrix	create_matrix_identity(int size);
t_tuple		multiply_matrix_id_by_tuple(t_tuple p);
t_matrix	transpose_matrix(t_matrix m);
// double		determinant(int	size, t_matrix m);
t_matrix	create_submatrix(t_matrix m, int row, int col);
// double		determinant_2(int size, t_matrix m);
double		calc_basic_determinant(int size, t_matrix m);

double		calc_minor(int size, t_matrix m, int row, int col);
double		cofactor(int size, t_matrix m, int row, int col);



# endif