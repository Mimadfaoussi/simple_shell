#include "main.h"

void     _putchar(int c)
{
        write(1, &c, 1);
}

void     _putstr(char *str)
{
        int     i;

        i = 0;
        while (str[i] != '\0')
        {
                _putchar(str[i]);
                i++;
        }
}

void	_error(void)
{
	_putstr("ERROR\n");
}
