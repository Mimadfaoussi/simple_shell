#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char	*line;
	size_t	size;
	ssize_t	nread;

	line = NULL;
	size = 0;
	printf("$ ");
	nread = getline(&line, &size, stdin);
	if (nread == -1)
	{
		free(line);
		return (0);
	}
	printf("%ld",nread);
	free(line);
	return (0);
}
