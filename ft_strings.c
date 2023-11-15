#include "main.h"

/**
 * _putchar-function that print a char c.
 * @c:char to print.
 * Return : void
 */

void	_putchar(int c)
{
	write(1, &c, 1);
}

/**
 * _putstr - function that print a string.
 * @str:string to print.
 * Return : void.
 */

void	_putstr(char *str)
{
	int     i;

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _error - function that print an error message.
 * Return : void.
 */

void	_error(void)
{
	_putstr("ERROR\n");
}

/**
 * ft_strlcat - function that concatinate two strings and add a null char.
 * @dst : destination .
 * @src : the source.
 * @dstsize : how much to copy.
 * Return: size.
 */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dsize;
	size_t	i;

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

