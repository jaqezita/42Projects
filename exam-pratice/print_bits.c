// Assignment name  : print_bits
// Expected files   : print_bits.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
// AT THE END.

// Your function must be declared as follows:

// void	print_bits(unsigned char octet);

// Example, if you pass 2 to print_bits, it will print "00000010"

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char	bit;
	int				index;
	
	index = 8;
	while (index > 0)
	{
		index--;
		bit = octet >> index;
		if (bit % 2 == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
}

int	main(void)
{
	unsigned char octet;

	octet = '9';

	print_bits(octet);
	return (0);
}