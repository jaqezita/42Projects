#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	i;
	int	j;
	int	*numbers;
	int temp;

	i = 0;
	temp = start; 
	while(temp <= end)
	{
		i++;
		temp++;
	}
	numbers = malloc(i * sizeof(int));
	if (numbers == NULL) // check if malloc succeeded
		return NULL;
	j = 0;
	while (end >= start)
	{
		numbers[j] = end;
		end--;
		j++;
	}
	return (numbers);
}

/* #include <stdio.h>

int main()
{
	int start = 1, end = 5;
	int *range = ft_rrange(start, end);

	if (range == NULL)
	{
		printf("Memory allocation failed\n");
		return 1;
	}

	for (int i = 0; i <= end - start; i++)
	{
		printf("%d ", range[i]);
	}

	free(range); // remember to free the allocated memory

	return 0;
}
 */