/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:13:07 by jaqribei          #+#    #+#             */
/*   Updated: 2023/07/21 16:27:51 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char c)
{
	if ((c < 65 || c > 90) && (c < 97 || c > 122))
		return (0);
	else
		return (1);
}
int main(void)
{
    printf ("%d\n", ft_isprint('\t'));
    printf ("%d\n", ft_isprint('\n'));
    printf ("%d\n", ft_isprint('\b'));
	
	return (0);
}