#include <stdlib.h>
#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	rostring(char *str)
{
	int	i;
	int	first_word_start;

	i = 0;
	while (str[i] && is_space(str[i]))
		i++;
	first_word_start = i;
	while (str[i] && !is_space(str[i]))
		i++;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i] && !is_space(str[i]))
		{
			while (str[i] && !is_space(str[i]))
			{
				write(1, &str[i], 1);
				i++;
			}
			write(1, " ", 1);
		}
	}
	i = first_word_start;
	while (str[i] && !is_space(str[i]))
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char *argv[])
{
	if (argc < 1)
		exit(write(1, "\n", 1));
	rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}