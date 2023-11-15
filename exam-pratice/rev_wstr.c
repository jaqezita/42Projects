// Assignment name  : rev_wstr
// Expected files   : rev_wstr.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string as a parameter, and prints its words in 
// reverse order.

// A "word" is a part of the string bounded by spaces and/or tabs, or the 
// begin/end of the string.

// If the number of parameters is different from 1, the program will display 
// '\n'.

// In the parameters that are going to be tested, there won't be any "additional" 
// spaces (meaning that there won't be additionnal spaces at the beginning or at 
// the end of the string, and words will always be separated by exactly one space).

// Examples:

// $> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
// ironic? it Isn't gatherings. love I But people! hate You$
// $>./rev_wstr "abcdefghijklm"
// abcdefghijklm
// $> ./rev_wstr "Wingardium Leviosa" | cat -e
// Leviosa Wingardium$
// $> ./rev_wstr | cat -e
// $
// $>

#include <unistd.h>
#include <stdlib.h>

// size_t	ft_strlen(const char *s)
// {
// 	unsigned int	len;

// 	len = 0;
// 	while (s != NULL && s[len] != '\0')
// 	{
// 		len++;
// 	}
// 	return (len);
// }

// char	*ft_strrchr(const char *s, int c)
// {
// 	int		index;
// 	char	*s_copy;

// 	s_copy = (char *)s;
// 	index = (ft_strlen(s_copy));
// 	while (index >= 0)
// 	{
// 		if (s_copy[index] == (char)c)
// 			return (s_copy + index);
// 		index--;
// 	}
// 	return (NULL);
// }

// void	ft_putstr(char *s)
// {
// 	int	index;

// 	index = 0;
// 	if (!s)
// 		return ;
// 	while (s[index] != '\0')
// 	{
// 		write (1, &s[index], 1);
// 		index++;
// 	}
// }

// int	main(int argc, char *argv[])
// {
// 	int		index;

// 	if (argc != 2)
// 		write(1, "\n", 1);
// 	index = ft_strlen(argv[1]) -1;
// 	while ((argv[1][index]) != '\0')
// 	{
// 		if(argv[1][index] == ' '|| argv[1][index] == '\t')
// 			ft_putstr(ft_strrchr(argv[1], (argv[1][index])));
// 		index = index - ft_strlen((ft_strrchr(argv[1], (argv[1][index]))));
		
// 	}
// 	return (0);
	
// }

int main(int argc, char **argv)
{
	int start;
	int end;
	int i = 0;
		
	if(argc == 2)
	{   
		while(argv[1][i] != '\0')
			i++;
		while(i >= 0)
		{
			while( argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
				i--;
			end = i;
			while(argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--;
			start = i + 1;
			int  flag;
			flag = start;
			while(start <= end)
			{
				write (1, &argv[1][start],1);
				start++;		
			}
			if (flag !=0)
			{
				write(1, " ", 1);
			}
		}
	}
	write(1, "\n", 1);
}