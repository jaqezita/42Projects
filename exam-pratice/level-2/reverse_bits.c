#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	unsigned char c;
	int bit;

	c = 0x0;
	bit = 0x0;
	while(bit < 8)
	{
		c <<= 1;
		if ((octet >> bit) & 1)
			c |= 1;
		bit++;
	}
	return (c);
}

int	main ()
{
	unsigned char octet = 'a';
	unsigned char c;

	c = swap_bits(octet);
	printf("%i\n", c);
	return (0);
}