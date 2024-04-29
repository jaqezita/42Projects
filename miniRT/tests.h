/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:48:14 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/25 10:03:24 by jaqribei         ###   ########.fr       */
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
# include "libassert.h"

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

typedef struct	s_ray
{
	t_tuple		origin;
	t_tuple		direction;
}				t_ray;

typedef struct	s_sphere
{
	t_tuple		center;
	double		radius;
	int			id;
}				t_sphere;

typedef struct	s_intersec
{
	double		t1;
	double		t2;
	t_sphere	*sphere;
}				t_intersec;

/**
 * @brief Create a tuple
 * 
 * @param x cordinate of vector
 * @param y cordinate of vector
 * @param z cordinate of vector
 * @param w cordinate of vector
 * @return t_tuple 
 **/	
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
t_matrix	create_submatrix(t_matrix m, int row, int col);
double		calc_determinant(int size, t_matrix m);
double		calc_minor(int size, t_matrix m, int row, int col);
double		cofactor(int size, t_matrix m, int row, int col);
t_matrix	calc_inverse_matrix(t_matrix m);
t_matrix	create_translation_matrix(double x, double y, double z);
t_matrix	create_scaling_matrix(double x, double y, double z);
t_matrix	create_rotation_matrix_x(double rad);
t_matrix	create_rotation_matrix_y(double rad);
t_matrix	create_rotation_matrix_z(double rad);
t_matrix	create_shearing_matrix(double proportion[6]);
t_ray		create_ray(t_tuple origin, t_tuple direction);
t_tuple		position(t_ray ray, double t);
t_sphere	create_sphere();






# endif