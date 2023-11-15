// Assignment name  : print_hex
// Expected files   : print_hex.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a positive (or zero) number expressed in base 10,
// and displays it in base 16 (lowercase letters) followed by a newline.

// If the number of parameters is not 1, the program displays a newline.

// Examples:

// $> ./print_hex "10" | cat -e
// a$
// $> ./print_hex "255" | cat -e
// ff$
// $> ./print_hex "5156454" | cat -e
// 4eae66$
// $> ./print_hex | cat -e
// $

#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	result;
	int	index;

	index = 0;
	result = 0;
	while (str[index] != '\0' && (str[index] >= 48 && str[index] <= 57))
	{
		result = result * 10 + str[index] - '0';
		index++;
	}
	return (result);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	putnbr_base(long int n)
{
	int	len;
	int	base_len;
	char *base;

	base = "0123456789abcdef";
	len = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		len += putnbr_base((n / base_len));
	}
	len += write(1, &base[n % base_len], 1);
	return (len);
}

int	main (int argc, char *argv[])
{
	int	n;

	if (argc != 2)
	return(write(1, "\n", 1));
	n = ft_atoi(argv[1]);
	putnbr_base(n);
	write(1, "\n", 1);
	return (0);
}