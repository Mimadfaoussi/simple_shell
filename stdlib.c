#include "main.h"

/**
 * ft_strlen - get length of a string
 * @s : the string.
 * Return:length of s.
 */

size_t  ft_strlen(const char *s)
{
	size_t  i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * ft_strncmp - compare two strings.
 * @s1 : string one.
 * @s2 : string two.
 * @n : nb of chars to compare.
 * Return:if > 0 if s1 bigger and reverse otherwise 0.
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t                  i;
	unsigned char   nbs1;
	unsigned char   nbs2;

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

