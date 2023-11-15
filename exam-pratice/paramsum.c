// Assignment name  : paramsum
// Expected files   : paramsum.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays the number of arguments passed to it, followed by
// a newline.

// If there are no arguments, just display a 0 followed by a newline.

// Example:

// $>./paramsum 1 2 3 5 7 24
// 6
// $>./paramsum 6 12 24 | cat -e
// 3$
// $>./paramsum | cat -e
// 0$
// $>

#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	unsigned int	len;

	len = 0;
	while (s != NULL && s[len] != '\0')
	{
		len++;
	}
	return (len);
}

static int	ft_putnbr_base(long int n, char *base)
{
	int	len;
	int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (n < 0)
	{
		len += write(1, "-", 1);
		if (n == -2147483648)
		{
			len += write (1, "2", 1);
			n = n + 2000000000;
		}
		n *= -1;
	}
	if (n >= base_len)
	{
		len += ft_putnbr_base((n / base_len), base);
	}
	len += write(1, &base[n % base_len], 1);
	return (len);
}

int	main(int argc, char *argv[])
{
	int		index;

	(void)argv;
	if (argc < 1)
    {
		write(1, "0", 1);
		write(1, "\n", 1);
    }
	index = 0;
	while (index < argc)
	{
		++index;
	}
	ft_putnbr_base((index - 1), "0123456789");
	write(1, "\n", 1);
	return (0);
}