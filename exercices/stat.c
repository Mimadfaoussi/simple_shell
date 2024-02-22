#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	int		st;
	int		i;
	struct stat	statbuf;

	i = 1;
	while (i < argc)
	{
		printf("%s ",argv[i]);
		if (stat(argv[i], &statbuf) == 0)
			printf("Found \n");
		else
			printf("Not found\n");
		i++;
	}
	return (0);
}

