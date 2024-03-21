#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int	result = 0;

	if (argc != 4)
	{
		exit(write(1, "\n", 1));
	}
	if (argv[2][0] == '+')
	{
		result = atoi(argv[1]) + atoi(argv[3]);
	}
	else if (argv[2][0] == '-')
	{
		result = atoi(argv[1]) - atoi(argv[3]);
	}
	else if (argv[2][0] == '*')
	{
		result = atoi(argv[1]) * atoi(argv[3]);
	}
	else if (argv[2][0] == '/')
	{
		result = atoi(argv[1]) / atoi(argv[3]);
	}
	else if (argv[2][0] == '%')
	{
		result = atoi(argv[1]) % atoi(argv[3]);
	}
	printf("%d\n", result);
	return (0);
}

