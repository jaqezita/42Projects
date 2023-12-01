#include <unistd.h>

int	main (int argc, char *argv[])
{
	int		index;
	char	c;

	if(argc != 2 || argv == NULL)
	{
		write(1, "\n", 1);
		return (0);
	}
	index = 0;
	while (argv[1][index] != '\0')
	{
		if ((argv[1][index] >= 65 && argv[1][index] <= 78) || (argv[1][index] >= 97 && argv[1][index] <= 109))
		{
			c = argv[1][index] + 13;
			write(1, &c, 1);
		}
		else if ((argv[1][index] >= 79 && argv[1][index] <= 90) || (argv[1][index] >= 110 && argv[1][index] <= 122))
		{
			c = argv[1][index] - 13;
			write(1, &c, 1);
		}
		else
			write(1, &argv[1][index], 1);
		index ++;
	}
	write(1, "\n", 1);
	return (0);
}