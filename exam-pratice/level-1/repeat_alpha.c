#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	index;
	int	repeat;

	index = 0;
	repeat = 1;
	if (argc != 2 || argv == NULL)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][index] != '\0')
	{
		if ((argv[1][index] >= 65 && argv[1][index] <= 90 )|| (argv[1][index] > 97 && argv[1][index] <= 122))
		{
			if (argv[1][index] >= 65 && argv[1][index] <= 90)
				repeat = argv[1][index] - 65 + 1;
			if (argv[1][index] >= 97 && argv[1][index] <= 122)
				repeat = argv[1][index] - 97 + 1;
			while (repeat > 0)
			{
				write(1, &argv[1][index], 1);
				repeat--;
			}
		}
		else
			write(1, &argv[1][index], 1);
		index++;
	}
	write(1, "\n", 1);
	return (0);
}