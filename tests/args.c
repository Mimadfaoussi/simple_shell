#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc)
		printf("--------- start -------- \n");
	while (*(argv + i))
	{
		printf("%s\n",*(argv + i));
		i++;
	}
	return (0);
}
