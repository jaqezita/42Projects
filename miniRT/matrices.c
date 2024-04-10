/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:59:42 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/10 16:57:38 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	free_matrix(t_matrix m)
{
	int		i;

	i = 0;
	while (i < m.size)
	{
		free(m.grid[i]);
		i++;
	}
	free(m.grid);
}

t_matrix	create_matrix(int size, double numbers[size][size])
{
	int			i;
	int			j;
	int			index;
	t_matrix	m;

	m.size = size;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			m.grid[i][j] = numbers[i][j];
			j++;
		}
		i++;
	}
	return (m);
}

int	matrix_equality(t_matrix a, t_matrix b)
{
	int	i;
	int	j;

	if (a.size != b.size)
		return (0);
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			if (a.grid[i][j] != b.grid[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_matrix	multiply_matrices(t_matrix a, t_matrix b)
{
	t_matrix	result;
	int			i;
	int			j;

	result.size = a.size;
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			result.grid[i][j] = (a.grid[i][0] * b.grid[0][j] \
								+ a.grid[i][1] * b.grid[1][j] \
								+ a.grid[i][2] * b.grid[2][j] \
								+ a.grid[i][3] * b.grid[3][j]);
			j++;
		}
		i++;
	}
	return (result);
}

t_tuple	multiply_matrix_by_tuple(t_matrix m, t_tuple p)
{
	t_tuple	result;
	t_tuple	x;
	t_tuple	y;
	t_tuple	z;
	t_tuple	w;

	x = create_tuple(m.grid[0][0], m.grid[0][1], m.grid[0][2], m.grid[0][3]);
	y = create_tuple(m.grid[1][0], m.grid[1][1], m.grid[1][2], m.grid[1][3]);
	z = create_tuple(m.grid[2][0], m.grid[2][1], m.grid[2][2], m.grid[2][3]);
	w = create_tuple(m.grid[3][0], m.grid[3][1], m.grid[3][2], m.grid[3][3]);
	result.x = dot_product(x, p);
	result.y = dot_product(y, p);
	result.z = dot_product(z, p);
	result.w = dot_product(w, p);
	return (result);
}

t_matrix	create_matrix_identity(int size)
{
	int			i;
	int			j;
	int			index;
	t_matrix	m;

	m.size = size;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == j)
				m.grid[i][j] = 1;
			else
				m.grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (m);
}

t_tuple	multiply_matrix_id_by_tuple(t_tuple p)
{
	t_matrix	m;
	t_tuple		result;
	t_tuple		x;
	t_tuple		y;
	t_tuple		z;
	t_tuple		w;

	m = create_matrix_identity(4);
	x = create_tuple(m.grid[0][0], m.grid[0][1], m.grid[0][2], m.grid[0][3]);
	y = create_tuple(m.grid[1][0], m.grid[1][1], m.grid[1][2], m.grid[1][3]);
	z = create_tuple(m.grid[2][0], m.grid[2][1], m.grid[2][2], m.grid[2][3]);
	w = create_tuple(m.grid[3][0], m.grid[3][1], m.grid[3][2], m.grid[3][3]);
	result.x = dot_product(x, p);
	result.y = dot_product(y, p);
	result.z = dot_product(z, p);
	result.w = dot_product(w, p);
	return (result);
}
