/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:36:12 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/03 18:27:21 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_tuple	create_tuple(double x, double y, double z, double w)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = w;
	return (t);
}

t_tuple	create_point(double x, double y, double z)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = 1.0;
	return (t);
}

t_tuple	create_vector(double x, double y, double z)
{
	t_tuple	t;

	t.x = x;
	t.y = y;
	t.z = z;
	t.w = 0.0;
	return (t);
}

bool	check_tuple_equality(t_tuple a, t_tuple b)
{
	double	x;
	double	y;
	double	z;
	double	w;

	x = fabs(a.x - b.x);
	y = fabs(a.y - b.y);
	z = fabs(a.z - b.z);
	w = fabs(a.w - b.w);
	if ((x < EPSILON) && (y < EPSILON) && (z < EPSILON) && (w < EPSILON))
		return (true);
	return (false);
}

t_tuple	add_tuples(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	result.w = a.w + b.w;
	return (result);
}

t_tuple	subtract_tuples(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	result.w = a.w - b.w;
	return (result);
}

t_tuple	deny_tuples(t_tuple a)
{
	t_tuple	result;

	result.x = -1 * (a.x);
	result.y = -1 * (a.y);
	result.z = -1 * (a.z);
	result.w = -1 * (a.w);
	return (result);
}

t_tuple	multiply_tuples(t_tuple a, double number)
{
	t_tuple	result;

	result.x = number * (a.x);
	result.y = number * (a.y);
	result.z = number * (a.z);
	result.w = number * (a.w);
	return (result);
}

t_tuple	divide_tuple(t_tuple a, double number)
{
	t_tuple	result;

	result.x = (a.x) / number;
	result.y = (a.y) / number;
	result.z = (a.z) / number;
	result.w = (a.w) / number;
	return (result);
}
