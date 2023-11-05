#include "main.h"

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
        return (i - 1);
}

int	_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	nbs1;
	unsigned char	nbs2;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		nbs1 = (unsigned char)s1[i];
		nbs2 = (unsigned char)s2[i];
		if (nbs1 != nbs2)
			return (nbs1 - nbs2);
		i++;
	}
	return (0);
}

int 	main(void)
{
	char	*buffer;
	ssize_t	bytesRead;
	ssize_t	w;
	size_t	n;
	int	keep;

	keep = 1;
	while (keep == 1)
	{
		w = _putstr("$im_shell# ");
		if (w == -1)
		{
			perror("ERROR");
			return (1);
		}
		buffer = NULL;
		n = 0;
		bytesRead = getline(&buffer, &n, stdin);
		if (bytesRead == -1)
		{
			perror("Error");
			return (1);
		}
		_putstr(buffer);
		if (_strncmp(buffer, "exit()", 6) == 0)
			keep = 0;
		free(buffer);
	}
	return (0);
}
