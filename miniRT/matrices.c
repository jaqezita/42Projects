/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:59:42 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/15 18:27:01 by jaqribei         ###   ########.fr       */
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

t_matrix	create_matrix(int size, double numbers[])
{
	int			i;
	int			j;
	int			k;
	t_matrix	m;

	m.size = size;
	i = 0;
	k = -1;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			m.grid[i][j] = numbers[++k];
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
	t_tuple	tuples[m.size];
	int		i;

	i = 0;
	while (i < m.size)
	{
		tuples[i] = create_tuple(m.grid[i][0], m.grid[i][1], m.grid[i][2], \
								m.grid[i][3]);
		i++;
	}
	result.x = dot_product(tuples[0], p);
	result.y = dot_product(tuples[1], p);
	result.z = dot_product(tuples[2], p);
	result.w = dot_product(tuples[3], p);
	return (result);
}

t_matrix	create_matrix_identity(int size)
{
	int			i;
	int			j;
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
	t_tuple		tuples[4];
	int			i;

	i = 0;
	m = create_matrix_identity(4);
	while (i < 4)
	{
		tuples[i] = create_tuple(m.grid[i][0], m.grid[i][1], m.grid[i][2], \
								m.grid[i][3]);
		i++;
	}
	result.x = dot_product(tuples[0], p);
	result.y = dot_product(tuples[1], p);
	result.z = dot_product(tuples[2], p);
	result.w = dot_product(tuples[3], p);
	return (result);
}

t_matrix	transpose_matrix(t_matrix m)
{
	int			i;
	int			j;
	t_matrix	result;

	result.size = m.size;
	i = 0;
	while (i < m.size)
	{
		j = 0;
		while (j < m.size)
		{
			result.grid[j][i] = m.grid[i][j];
			j++;
		}
		i++;
	}
	return (result);
}

void	fill_submatrix(t_matrix m, t_matrix *sub, int del_row, int del_col)
{
	int	row;
	int	col;
	int	x;
	int	y;

	x = 0;
	row = 0;
	while (row < m.size)
	{
		if (row != del_row)
		{
			y = 0;
			col = 0;
			while (col < m.size)
			{	
				if (col != del_col)
					sub->grid[x][y++] = m.grid[row][col];
				col++;
			}
			x++;
		}
		row++;
	}
}

t_matrix	create_submatrix(t_matrix m, int del_row, int del_col)
{
	t_matrix	submatrix;

	submatrix.size = m.size - 1;
	fill_submatrix(m, &submatrix, del_row, del_col);
	return (submatrix);
}

void	fill_loop(int size, t_matrix m, t_matrix *sub, int i, int *sub_index)
{
	int	j;
	int	k;

	j = 1;
	while (j < size)
	{
		*sub_index = 0;
		k = 0;
		while (k < size)
		{
			if (k != i)
				sub->grid[(*sub_index)++][j - 1] = m.grid[k][j];
			k++;
		}
		j++;
	}
}

double	calc_determinant(int size, t_matrix m, double det, t_matrix sub)
{
	int		i;
	int		sub_index;
	double	sign;

	sign = 1;
	i = 0;
	while (i < size)
	{
		sub.size = size - 1;
		fill_loop(size, m, &sub, i, &sub_index);
		det += sign * m.grid[0][i] * calc_basic_determinant(size - 1, sub);
		sign = -sign;
		i++;
	}
	return (det);
}

double	calc_basic_determinant(int size, t_matrix m)
{
	t_matrix	submatrix;
	double		determinant;

	determinant = 0;
	if (size == 1)
		return (m.grid[0][0]);
	else if (size == 2)
		return (m.grid[0][0] * m.grid[1][1] - m.grid[0][1] * m.grid[1][0]);
	else
		return (calc_determinant(size, m, determinant, submatrix));
}

double	calc_minor(int size, t_matrix m, int row, int col)
{
	t_matrix	submatrix;
	double		minor;
	double		determinant;

	submatrix = create_submatrix(m, row, col);
	determinant = calc_basic_determinant(submatrix.size, submatrix);
	minor = determinant;
	return (minor);
}

double	cofactor(int size, t_matrix m, int row, int col)
{
	double	minor;
	double	cofactor;

	minor = calc_minor(size, m, row, col);
	if ((row + col) % 2 != 0)
		cofactor = -minor;
	else
		cofactor = minor;
	return (cofactor);
}


