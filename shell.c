#include "main.h"

int main()
{
	int	keep;
	char	*buffer;
	size_t	n;
	ssize_t	bytesRead;

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
		_putstr(buffer);
		_putchar('\n');
		return (0);
	}
}
