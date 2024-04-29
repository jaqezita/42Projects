/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 01:12:23 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/22 19:32:19 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_ray		create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

t_tuple		position(t_ray ray, double t)
{
	t_tuple	position;

	position = add_tuples(ray.origin, multiply_tuples_scalar(ray.direction, t));
	return (position);
}

t_sphere	create_sphere()
{
	t_sphere	sphere;
	static int	id = 0;

	sphere.center = create_point(0, 0, 0);
	sphere.radius = 1.0;
	sphere.id = id++;
	return (sphere);
}

t_tuple sphere_to_ray(t_ray ray, t_tuple point)
{
	t_tuple result;

	result = subtract_tuples(ray.origin, create_point(0, 0, 0));
	return (result);
}

double	calc_discriminant(t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	t_sphere	sphere;

	a = dot_product(ray.direction, ray.direction);
	b = 2 * (dot_product(ray.direction, sphere_to_ray(ray, sphere.center)));
	c = dot_product(sphere_to_ray(ray, sphere.center), sphere_to_ray(ray, sphere.center)) - 1;
	discriminant = pow(b, 2) - (4 * a * c);
	return (discriminant);
}

// t_intersec	intersect(t_ray ray)
// {
// 	t_intersec	intersec;
// 	double		discriminant;
// 	double		t1;
// 	double		t2;
// 	t_sphere	sphere;

// 	discriminant = calc_discriminant(ray);
// 	if (discriminant < 0)
// 	{
// 		intersec.t1 = INFINITY;
// 		intersec.t2 = INFINITY;
// 		intersec.sphere = NULL;
// 		return (intersec);
// 	}
// 	t1 = (-dot_product(ray.direction, sphere_to_ray(ray, sphere.center)) - sqrt(discriminant)) / (2 * dot_product(ray.direction, ray.direction));
// 	t2 = (-dot_product(ray.direction, sphere_to_ray(ray, sphere.center)) + sqrt(discriminant)) / (2 * dot_product(ray.direction, ray.direction));
// 	intersec.t1 = t1;
// 	intersec.t2 = t2;
// 	intersec.sphere = &sphere;
// 	return (intersec);
// }
