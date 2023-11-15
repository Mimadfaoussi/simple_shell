#include "main.h"

int main(int argc, char **argv)
{
	int	keep;
	pid_t	pid;
	char	*buffer;
	size_t	n;
	ssize_t	bytesRead;
	int	status;
	char	**list;

	if (argc < 1)
		return (1);
	list = malloc(sizeof(char *) * 2);
	keep = 1;
	while (keep == 1)
	{
		_putstr("$ ");
		buffer = NULL;
		n = 0;
		bytesRead = getline(&buffer, &n, stdin);
		if (bytesRead == -1)
		{
			_putstr("End of file (Ctrl+D) detected. Exiting.\n");
			free(buffer);
			return (0);
		}
		if (bytesRead > 0 && buffer[bytesRead - 1] == '\n')
			buffer[bytesRead - 1] = '\0';
		if (*buffer == '\0' || buffer == NULL || ft_strlen(buffer) == 0)
			continue;
		list = ft_split((char const *)buffer, ' ');
		if (ft_strncmp(buffer, "exit" , 4) == 0)
                {
			keep = 0;
			free(buffer);
			free(list);
			return (0);
		}
		if (find_file_path(list[0]) == NULL)
		{
			_putstr(argv[0]);
			_putstr(": No such file or directory\n");
		}
		else
		{
			fullpath(list);
			pid = fork();
			if (pid == -1)
			{
				_error();
				return (1);
			}
			if (pid == 0)
			{
				if (execve(list[0], list, NULL) == -1)
				{
					_putstr(argv[0]);
					_putstr(": No such file or directory\n");
				}
				return (0);
			}
			wait(&status);
		}
	}
	return (0);
}
