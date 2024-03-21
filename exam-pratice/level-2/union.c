#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


char	*selfcmp(char **arg)
{
	char *dest = malloc(260 * sizeof(char));
	int		i;
	int		j = 0;
	int		x; 
	int		z;

	x = 0;
	z = 1;
	while (z < 2)
	{	
		i = 0;
		while(arg[z][i] != '\0')
		{
			j += i;
			while (arg[z][j] != '\0')
			{
				if (arg[z][i] == arg[z][j])
					j++;
				else
					dest[x++] = arg[z][i];
				j++;
			}
			i++;
		}
		z++;
	}
	dest[x] ='\0';
	return (dest);
}

int	main (int argc, char *argv[])
{
	int		index;

	index = 0;
	if (argc != 3 || argv == NULL)
	{
		write(1, "\n", 1);
		return (0);
	}
	printf ("%s\n", selfcmp(argv));
	return (0);
}