/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:04:32 by jaqribei          #+#    #+#             */
/*   Updated: 2023/07/24 15:55:13 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	result;
	int	index;
	int	sign;

	sign = 1;
	index = 0;
	while ((nptr[index] >= 9 && nptr[index] <= 13) || nptr[index] == 32)
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			sign = sign * -1;
		index++;
	}
	result = 0;
	while (nptr[index] != '\0' && (nptr[index] >= 48 && nptr[index] <= 57))
	{
		result = result * 10 + nptr[index] - '0';
		index++;
	}
	return (result * sign);
}

/* #include <stdio.h>
int		main(void)
{
	char	*str;

	str = " 	 -+-+454687";

	printf("%d", ft_atoi(str));

	return (0);
} */
