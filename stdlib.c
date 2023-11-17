#include "shell.h"

/**
 * ft_strlen - Get the length of a string.
 * @s: The string.
 * Return: Length of s.
 */
size_t ft_strlen(const char *s)
{
	size_t i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * ft_strncmp - Compare two strings.
 * @s1: String one.
 * @s2: String two.
 * @n: Number of characters to compare.
 * Return: 0 if equal, > 0 if s1 is greater, < 0 otherwise.
 */
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		unsigned char nbs1 = (unsigned char)s1[i];
		unsigned char nbs2 = (unsigned char)s2[i];
		if (nbs1 != nbs2)
			return nbs1 - nbs2;
		i++;
	}
	return 0;
}
