#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	result;

	if (argc != 3)
		exit(write(1, "\n", 1));
	i = 1;
	result = 1;
	while (atoi(argv[1]) >= i && atoi(argv[2]) >= i)
	{	
		if (atoi(argv[1]) % i == 0 && atoi(argv[2]) % i == 0)
			result = i;
		i++;
	}
	printf("%d\n", result);
	return (0);
}