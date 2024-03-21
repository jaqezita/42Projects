#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	ascii[128] = {0};
	int	ascii2[128] = {0};
	int	i;

	if (argc != 3)
		return (write(1, "\n", 1));
	i = 0;
	while (argv[2][i] != '\0')
	{
		if (ascii2[((int)argv[2][i])] == 0)
			ascii2[((int)argv[2][i])] = 1;
		i++;
	}
	i = 0;
	while (argv[1][i] != '\0')
	{
		if (ascii[(int)argv[1][i]] == 0 && ascii2[(int)argv[1][i]] == 1) 
		{
			write(1, &argv[1][i], 1);
			ascii[(int)argv[1][i]] = 1;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}