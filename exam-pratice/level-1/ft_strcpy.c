char	*ft_strcpy(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s2[index] != '\0')
	{
		s1[index] = s2[index];
		index++;
	}
	s1[index] = '\0';
	return (s1);
}

/* #include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	dest[255];

	printf("%s\n", ft_strcpy(dest, "Blackpink In Your Area"));
	printf("%s\n", ft_strcpy(dest, "Jaqueline"));
	printf("%s\n", ft_strcpy(dest, "1 2 3 4 5 6 7 8 9"));
	printf("%s\n", ft_strcpy(dest, "Hell0, W0lrd!"));
	printf("%s\n", ft_strcpy(dest, ""));
	printf("%s\n", ft_strcpy(dest, "   "));
	return (0);
} */