#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return(len);
}

int	main(int argc, char *argv[])
{
	int		index;

	if(argc != 4 || argv == NULL || ft_strlen(argv[2]) > 1|| ft_strlen(argv[3]) > 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	index = 0;
	while (argv[1][index] != '\0')
	{
		if (argv[1][index] == argv[2][0])
		{
			argv[1][index] = argv[3][0];
			write(1, &argv[1][index], 1);
		}
		else 
			write(1, &argv[1][index], 1);
		index++;
	}
	write(1, "\n", 1);
	return (0);
}