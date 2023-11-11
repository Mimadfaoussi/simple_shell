#include "main.h"

int main(void)
{
	int	keep;
	pid_t	pid;
	char	*buffer;
	size_t	n;
	ssize_t	bytesRead;
	int	status;
	//char	*list[] = {"/bin/ls", "-l", "/tmp/", NULL};
	char	**list;

	list = malloc(sizeof(char *) * 2);
	list[1] = NULL;
	keep = 1;
	while (keep == 1)
	{
		_putstr("$ ");
		buffer = NULL;
		n = 0;
		bytesRead = getline(&buffer, &n, stdin);
		if (bytesRead == -1)
		{
			_error();
			return (1);
		}
		if (bytesRead > 0 && buffer[bytesRead - 1] == '\n')
			buffer[bytesRead - 1] = '\0';
		list[0] = buffer;
		if (ft_strncmp(buffer, "exit" , 4) == 0)
                {
			keep = 0;
			free(buffer);
			free(list);
			return (0);
		}
		pid = fork();
		if (pid == -1)
		{
			_error();
			return (1);
		}
		if (pid == 0)
		{
			if (execve(list[0], list, NULL) == -1)
				perror("_error");
			return (0);
		}
		wait(&status);
		if (ft_strncmp(buffer, "exit" , 4) == 0)
                        keep = 0;
		free(buffer);
	}
	return (0);
}
