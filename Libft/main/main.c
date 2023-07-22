/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:28:31 by jaqribei          #+#    #+#             */
/*   Updated: 2023/07/22 19:23:39 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>


int	ft_isalpha(char c);

/* int main(void)
{
    printf ("%d\n", ft_isalpha('0'));
    printf ("%d\n", ft_isalpha('a'));
    printf ("%d\n", ft_isalpha('~'));
    printf ("%d\n", ft_isalpha('-'));
    printf ("%d\n", ft_isalpha('='));
    printf ("%d\n", ft_isalpha('A'));
    printf ("%d\n", ft_isalpha('F'));

    return (0);
} */

int	ft_isdigit(char c);

/* int main(void)
{
    printf ("%d\n", ft_isdigit('0'));
    printf ("%d\n", ft_isdigit('1'));
    printf ("%d\n", ft_isdigit('2'));
    printf ("%d\n", ft_isdigit('3'));
    printf ("%d\n", ft_isdigit('4'));
    printf ("%d\n", ft_isdigit('5'));
    printf ("%d\n", ft_isdigit(55));
	printf ("%d\n", ft_isdigit('7'));
    printf ("%d\n", ft_isdigit('8'));
    printf ("%d\n", ft_isdigit('9'));
	printf ("%d\n", ft_isdigit('a'));
    printf ("%d\n", ft_isdigit('B'));
    printf ("%d\n", ft_isdigit('-'));

    return (0);
} */

int	ft_isalnum(char c);

/*int main(void)
{
    printf ("%d\n", ft_isalnum('0'));
    printf ("%d\n", ft_isalnum('1'));
    printf ("%d\n", ft_isalnum('2'));
    printf ("%d\n", ft_isalnum('3'));
    printf ("%d\n", ft_isalnum('4'));
    printf ("%d\n", ft_isalnum('5'));
    printf ("%d\n", ft_isalnum(55));
	printf ("%d\n", ft_isalnum('7'));
    printf ("%d\n", ft_isalnum('8'));
    printf ("%d\n", ft_isalnum('9'));
	printf ("%d\n", ft_isalnum('a'));
    printf ("%d\n", ft_isalnum('B'));
    printf ("%d\n", ft_isalnum('-'));
	printf ("%d\n", ft_isalnum('0'));
    printf ("%d\n", ft_isalnum('a'));
    printf ("%d\n", ft_isalnum('~'));
    printf ("%d\n", ft_isalnum('-'));
    printf ("%d\n", ft_isalnum('='));
    printf ("%d\n", ft_isalnum('A'));
    printf ("%d\n", ft_isalnum('F'));

	return (0);
} */

int	ft_isascii(char c);

/* int main(void)
{
    printf ("%d\n", ft_isascii('0'));
    printf ("%d\n", ft_isascii('1'));
    printf ("%d\n", ft_isascii('2'));
    printf ("%d\n", ft_isascii('3'));
    printf ("%d\n", ft_isascii('4'));
    printf ("%d\n", ft_isascii('5'));
    printf ("%d\n", ft_isascii(55));
	printf ("%d\n", ft_isascii('7'));
    printf ("%d\n", ft_isascii('8'));
    printf ("%d\n", ft_isascii('9'));
	printf ("%d\n", ft_isascii('a'));
    printf ("%d\n", ft_isascii('B'));
    printf ("%d\n", ft_isascii('-'));
	printf ("%d\n", ft_isascii('0'));
    printf ("%d\n", ft_isascii('a'));
    printf ("%d\n", ft_isascii('~'));
    printf ("%d\n", ft_isascii('-'));
    printf ("%d\n", ft_isascii('='));
    printf ("%d\n", ft_isascii('ã'));
    printf ("%d\n", ft_isascii(ê));

	return (0);
}  */

int	ft_isprint(char c);

/* int main(void)
{
    printf ("%d\n", ft_isprint('\t'));
    printf ("%d\n", ft_isprint('\n'));
    printf ("%d\n", ft_isprint('\b'));
	
	return (0);
} */

int	ft_strlen(char *str);

/* int	main(void)
{
	char	*str;
	char 	c;
	
	str = "Jaque";
	
	c = ft_strlen(str) + '0';
	
	write (1, &c, 1);
} */