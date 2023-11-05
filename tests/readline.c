#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int     _putchar(int c)
{
        write(1, &c, 1);
        return (1);
}

int     _putstr(char *str)
{
        int     i;

        i = 0;
        while (str[i] != '\0')
        {
                _putchar(str[i]);
                i++;
        }
        return (i);
}

int main(int argc, char **argv)
{
	ssize_t	w;
	ssize_t bytesRead;
	char	*buffer;
	size_t	n;

	w = write(1, "$ ", 2);
	if (argc && argv)
		write (1, "", 0);
	if (w == -1)
	{
		perror("ERROR\n");
		return (1);
	}
	buffer = NULL;
	n = 0;
	bytesRead = getline(&buffer, &n, stdin);
	if (bytesRead != -1)
        {
                _putstr(buffer);
        }
        else
        {
                _putstr("i am stupid\n");
        }
        free(buffer);
	return (0);
}
