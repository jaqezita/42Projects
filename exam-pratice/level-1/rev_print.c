#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	main(int argc, char *argv[])
{
	int	index;

	if (argc != 2 || argv == NULL)
	{
		write (1, "\n", 1);
		return (0);
	}
	index = ft_strlen(argv[1]) - 1;
	while (argv[1][index] != '\0')
	{
		write(1, &argv[1][index], 1);
		index--;
	}
	write (1, "\n", 1);
	return (0);
}