#include <unistd.h>

void	check(char *arg1, char *arg2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg1[i] != '\0')
	{
		while ((arg1[i] != arg2[j]) && arg2[j] != '\0')
			j++;
		if(arg2[j] == '\0')
		{
			write(1, "0", 1);
			return;
		}
		j++;
		i++;
	}
	write(1, "1", 1);
}

int	main(int argc, char *argv[])
{
	if (argc != 3 || argv == NULL)
	{
		write(1, "\n", 1);
		return (0);
	}
	check(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

