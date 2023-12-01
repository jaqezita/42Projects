#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	index;

	if (argc != 2 || argv == NULL)
		return (write(1, "\n", 1));
	index = 0;
	while (argv[1][index] == ' ' || argv[1][index] == '\t')
		index++;
	while (argv[1][index] != ' ' && argv[1][index] != '\t' && argv[1][index] != '\0')
	{	
		write(1, &argv[1][index], 1);
		index++;
	}
	return (write(1, "\n", 1));
	return (0);
}