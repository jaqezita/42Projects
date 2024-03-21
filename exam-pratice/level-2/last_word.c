#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	int	i;
	int j;

	if(argc != 2 || argv == NULL)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = ft_strlen(argv[1]) - 1;
	j = ft_strlen(argv[1]) - 1;
	while ((argv[1][i] == ' ' || argv[1][i] == '\t') && i != 0)
		i--;
	while (argv[1][i] != ' ' && argv[1][i] != '\t' && i != 0)
		i--;
	while (i <= j)
	{
		if (argv[1][i] == ' ' || argv[1][i] == '\t')
				i++;
		else 
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}