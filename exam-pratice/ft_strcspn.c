// Assignment name	: ft_strcspn
// Expected files	: ft_strcspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the function strcspn
// (man strcspn).

// The function should be prototyped as follows:

// size_t	ft_strcspn(const char *s, const char *reject);

// DESCRIPTION
//        The strcspn() function calculates the length of the initial segment  of
//        s which consists entirely of bytes not in reject.

// RETURN VALUE
//        The  strspn()  function returns the number of bytes in the initial seg‐
//        ment of s which consist only of bytes from accept.

#include <unistd.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == reject[j])
			return (i);
		i++;
	}
	return (i);
}

#include <stdio.h>

int main(void)
{
	const char *s;
	const char *reject;
	int 		len;

	len = 0;
	s = "hello World";
	reject = "hello world";

	len = (int)ft_strcspn("hello World", "hello world");
	printf ("%d", len);
	return (0);
}