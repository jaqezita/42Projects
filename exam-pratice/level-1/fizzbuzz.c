#include <unistd.h>

void	ft_recursive(int n)
{
	char	charnumber;

	if (n / 10 == 0)
	{
		charnumber = (n % 10) + '0';
		write (1, &charnumber, 1);
		return ;
	}
	ft_recursive(n / 10);
	charnumber = (n % 10) + '0';
	write (1, &charnumber, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
		{
			write (1, "2", 1);
			n = n + 2000000000;
		}
		n *= -1;
		ft_recursive(n);
	}
	else
		ft_recursive(n);
}

int	main(void)
{
	int	number;

	number = 1;
	while(number <= 100)
	{
		if (number % 3 == 0 && number % 5 == 0)
		{
			write(1, "fizzbuzz", 8);
			write(1, "\n", 1);
		}
		else if (number % 3 == 0)
		{
			write(1, "fizz", 4);
			write(1, "\n", 1);
		}
		else if (number % 5 == 0)
		{
			write(1, "buzz", 4);
			write(1, "\n", 1);
		}
		else if (number % 3 != 0 && number % 5 != 0)
		{
			ft_putnbr(number);
			write(1, "\n", 1);
		}
		number++;
	}
}