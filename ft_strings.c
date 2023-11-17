#include "shell.h"

/**
 * _putchar - Prints a character.
 * @c: Character to print.
 * Return: void.
 */
void _putchar(int c)
{
	write(1, &c, 1);
}

/**
 * _putstr - Prints a string.
 * @str: String to print.
 * Return: void.
 */
void _putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _error - Prints an error message.
 * Return: void.
 */
void _error(void)
{
	_putstr("ERROR\n");
}

/**
 * ft_strlcat - Concatenates two strings and adds a null character.
 * @dst: Destination.
 * @src: Source.
 * @dstsize: How much to copy.
 * Return: Size.
 */
size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dsize;
	size_t i;

	dsize = ft_strlen(dst);
	if (dstsize <= dsize)
		return (dstsize + ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && dsize < dstsize - 1)
	{
		dst[dsize] = src[i];
		dsize++;
		i++;
	}
	dst[dsize] = '\0';
	return (dsize + ft_strlen(src + i));
}
