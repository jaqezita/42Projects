/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:45:46 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/03 18:27:21 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

bool	is_point(t_tuple t)
{
	return (t.w == 1.0);
}

bool	is_vector(t_tuple t)
{
	return (t.w == 0.0);
}

int	main(void)
{
	// t_tuple a = {atof(argv[1]), atof(argv[2]), atof(argv[3]), atof(argv[4])};
	t_tuple a = {4.3, -4.2, 3.1, 1.0};
	t_tuple b = {4.3, -4.2, 3.1, 0.0};
	
	printf("\033[1;35mchecking point/vector\033[0m\n");
	if (is_point(a))
		printf("t_tuple a = {4.3, -4.2, 3.1, 1.0} is a point\n");
	if (is_point(b))
		printf("t_tuple b = {4.3, -4.2, 3.1, 0.0} is a point\n");
	if (is_vector(a))
		printf("t_tuple a = {4.3, -4.2, 3.1, 1.0} is a point\n");
	if (is_vector(b))
		printf("t_tuple b = {4.3, -4.2, 3.1, 0.0} is a vector\n");
	
	printf("\n\033[1;35mchecking create points/vector\033[0m");
	t_tuple p = create_point(4, -4, 3);
		printf("\npoint: x %f, y %f, z %f, w %f\n", p.x, p.y, p.z, p.w);
	t_tuple v = create_vector(4, -4, 3);
		printf("vector: x %f, y %f, z %f, w %f\n\n", v.x, v.y, v.z, v.w);
	
	printf("\033[1;35mchecking if tuples are equals\033[0m\n");
	if (check_tuple_equality(a, b))
		printf("a and b are equal\n");
	else
		printf("a and b are not equal\n");

	printf("\n\033[1;35madding tuples\033[0m\n");
	t_tuple a1 = {3, -2, 5, 1};
	t_tuple a2 = {-2, 3, 1, 0};
	t_tuple expect = {1, 1, 6, 1};
	t_tuple result = add_tuples(a1, a2);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect.x, expect.y, expect.z, expect.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result.x, result.y, result.z, result.w);
	if (check_tuple_equality(expect, result))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");
		
	printf("\n\033[1;35msubtracting a vector from a point\033[0m\n");
	t_tuple p1 = {3, 2, 1, 1};
	t_tuple p2 = {5, 6, 7, 1};
	t_tuple expect_s = {-2, -4, -6};
	t_tuple result_s = subtract_tuples(p1, p2);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect_s.x, expect_s.y, expect_s.z, expect_s.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result_s.x, result_s.y, result_s.z, result_s.w);
	if (check_tuple_equality(expect_s, result_s))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");
	
	printf("\n\033[1;35mSubtracting a vector from a point\033[0m\n");
	t_tuple point = {3, 2, 1, 1};
	t_tuple vector = {5, 6, 7, 0};
	t_tuple expect_r = {-2, -4, -6, 1};
	t_tuple result_r = subtract_tuples(point, vector);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect_r.x, expect_r.y, expect_r.z, expect_r.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result_r.x, result_r.y, result_r.z, result_r.w);
	if (check_tuple_equality(expect_r, result_r))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");
		
	printf("\n\033[1;35msubtracting two vectors\033[0m\n");
	t_tuple v1 = {3, 2, 1, 0};
	t_tuple v2 = {5, 6, 7, 0};
	t_tuple expect_v = {-2, -4, -6};
	t_tuple result_v = subtract_tuples(v1, v2);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect_v.x, expect_v.y, expect_v.z, expect_v.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result_v.x, result_v.y, result_v.z, result_v.w);
	if (check_tuple_equality(expect_v, result_v))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");

	printf("\n\033[1;35mSubtracting a vector from the zero vector\033[0m\n");
	t_tuple zero = {0, 0, 0, 0};
	t_tuple vzero = {1, -2, 3, 0};
	t_tuple expect_z = {-1, 2, -3};
	t_tuple result_z = subtract_tuples(zero, vzero);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect_z.x, expect_z.y, expect_z.z, expect_z.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result_z.x, result_z.y, result_z.z, result_z.w);
	if (check_tuple_equality(expect_z, result_z))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");

	printf("\n\033[1;35mNegating a tuple\033[0m\n");
	t_tuple neg = {1, -2, 3, -4};
	t_tuple expect_n = {-1, 2, -3, 4};
	t_tuple result_n = deny_tuples(neg);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect_n.x, expect_n.y, expect_n.z, expect_n.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result_n.x, result_n.y, result_n.z, result_n.w);
	if (check_tuple_equality(expect_n, result_n))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");

	printf("\n\033[1;35mMultiplying a tuple by a scalar\033[0m\n");
	double scalar = 3.5;
	t_tuple m = {1, -2, 3, -4};
	t_tuple expect_m = {3.5, -7, 10.5, -14};
	t_tuple result_m = multiply_tuples(m, scalar);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect_m.x, expect_m.y, expect_m.z, expect_m.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result_m.x, result_m.y, result_m.z, result_m.w);
	if (check_tuple_equality(expect_m, result_m))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");

	printf("\n\033[1;35mMultiplying a tuple by a fraction\033[0m\n");
	double fr = 0.5;
	t_tuple frac = {1, -2, 3, -4};
	t_tuple expect_f = {0.5, -1, 1.5, -2};
	t_tuple result_f = multiply_tuples(frac, fr);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect_f.x, expect_f.y, expect_f.z, expect_f.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result_f.x, result_f.y, result_f.z, result_f.w);
	if (check_tuple_equality(expect_f, result_f))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");

	printf("\n\033[1;35mDividing a tuple by a scalar\033[0m\n");
	double div = 2;
	t_tuple dividend = {1, -2, 3, -4};
	t_tuple expect_div = {0.5, -1, 1.5, -2};
	t_tuple result_div = divide_tuple(dividend, div);
	printf ("expect: %.1f, %.1f, %.1f, %.1f\n", expect_div.x, expect_div.y, expect_div.z, expect_div.w);
	printf ("result: %.1f, %.1f, %.1f, %.1f\n", result_div.x, result_div.y, result_div.z, result_div.w);
	if (check_tuple_equality(expect_div, result_div))
		printf("\33[1;32mOK\n");
	else
		printf("\33[1;31mFAIL\n");
	return (0);
}