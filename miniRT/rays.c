/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 01:12:23 by jaqribei          #+#    #+#             */
/*   Updated: 2024/06/11 19:07:57 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_ray		create_ray(t_tuple origin, t_tuple direction) // create a ray
{
	t_ray	ray;

	ray.origin = create_point(origin.x, origin.y, origin.z);
	ray.direction = create_vector(direction.x, direction.y, direction.z);
	return (ray);
}

t_tuple		position(t_ray ray, double t) // position of the ray at time t
{
	t_tuple	position;

	position = add_tuples(ray.origin, multiply_tuples_scalar(ray.direction, t));
	return (position);
}

t_sphere	create_sphere() // create a sphere at the origin
{
	t_sphere	sphere;
	static int	id = 0;

	sphere.center = create_point(0, 0, 0);
	sphere.radius = 1.0;
	sphere.id = id++;
	return (sphere);
}

t_tuple sphere_to_ray(t_ray ray, t_sphere sphere)
{
	t_tuple	result;

	result = subtract_tuples(ray.origin, sphere.center);
	return (result);
}

t_discriminant	calc_discriminant(t_ray ray, t_sphere sphere)
{
	t_discriminant	discriminant;
	
	discriminant.a = dot_product(ray.direction, ray.direction);
	discriminant.b = 2 * dot_product(ray.direction, sphere_to_ray(ray, sphere));
	discriminant.c = dot_product(sphere_to_ray(ray, sphere), sphere_to_ray(ray, sphere)) - 1;
	discriminant.discriminant = pow(discriminant.b, 2) - (4 * discriminant.a * discriminant.c);
	return (discriminant);
}

t_intersect *create_intersection_node(double t, t_sphere *sphere)
{
	t_intersect *node;

	node = (t_intersect*)malloc(sizeof(t_intersect));
	if (!node) 
		return NULL;
	node->t = t;
	node->sphere = sphere;
	node->next = NULL;
	return (node);
}

void add_intersection(t_intersect **head, double t, t_sphere *sphere)
{
	t_intersect *new_node;
	
	new_node = create_intersection_node(t, sphere);
	if (*head == NULL || t < (*head)->t)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		t_intersect *current = *head;
		while (current->next!= NULL && current->next->t < t) 
			current = current->next;
		new_node->next = current->next;
		current->next = new_node;
	}
}

t_intersec	intersect(t_ray ray, t_sphere sphere, t_discriminant discriminant)
{
	
	t_intersec			intersec;

	discriminant = calc_discriminant(ray, sphere);
	if (discriminant.discriminant < 0)
		return (intersec);
	t1 = (-1.0 * discriminant.b - sqrt(discriminant.discriminant)) / (2.0 * discriminant.a);
	t2 = (-1.0 * discriminant.b + sqrt(discriminant.discriminant)) / (2.0 * discriminant.a);
	intersec.t[0] = t1;
	intersec.t[1] = t2;
	intersec.count = 2;
	return (intersec);
}

t_intersections intersections(t_ray ray, t_sphere sphere)
{
	t_discriminant		discriminant;
	t_intersection		intersection;

	discriminant = calc_discriminant(ray, sphere);
	
	
}

t_ray		transform_ray(t_ray ray, t_matrix matrix)
{
	t_ray		result;

	result.origin = multiply_matrix_by_tuple(matrix, ray.origin);
	result.direction = multiply_matrix_by_tuple(matrix, ray.direction);
	return (result);
}

t_sphere	set_transform(t_sphere sphere, t_matrix matrix)
{
	sphere.transform = matrix;
	return (sphere);
}

