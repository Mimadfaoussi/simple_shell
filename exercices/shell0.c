#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


int	_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


/**
 * _strcmp-compare 2 strings
 * @str:first string
 * @new:second string
 * Return:0 if different and 1 if the same
 */


int	_strcmp(char *str, char *new, int n)
{
	int	i;
	int	size;

	i = 0;
	while (str[i] && new[i] && i < n)
	{
		if (str[i] != new[i])
			return (0);
		i++;
	}
	if (str[i] && !new[i])
		return (0);
	if (new[i] && !str[i])
		return (0);
	return (1);
}

int main(void)
{
	char	*lineptr;
	size_t	n;
	ssize_t	size;
	pid_t	pid;
	int	status;

	lineptr = NULL;
	n = 0;
	while (1)
	{
		printf("$ ");
		size = getline(&lineptr, &n, stdin);
		pid = fork();
		if (pid == 0)
		{
			lineptr[_strlen(lineptr) - 1] = '\0';
			if (execve(lineptr, (char *[]){lineptr, "-l", NULL}, NULL) == -1)
				perror("error:");
		}
		wait(&status);
	}
	free(lineptr);
	return (0);
}

