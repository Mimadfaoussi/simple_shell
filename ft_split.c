#include "shell.h"

/**
 * ft_strlcpy - function that copy string from source to dst
 * @dst:destination
 * @src : source
 * @destsize:destination size
 * Return: nb of copied chars.
 */

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	src_length;

	src_length = ft_strlen(src);
	if (!src || !dst)
		return (0);
	if (destsize > 0)
	{
		i = 0;
		while (src[i] != '\0' && (i < destsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_length);
}

/**
 * put - function that create a string for split.
 * @str:string to work on.
 * @index:where to start.
 * @c: delimiter char.
 * Return: created string.
 */

char    *put(char const *str, int *index, char c)
{
	int             i;
	int             length;
	char    *result;

	i = *index;
	length = 0;
	while (str[i] == c && str[i] != '\0')
	{
		i++;
		*index = *index + 1;
	}
	while (str[*index] != c && str[*index] != '\0')
	{
		*index = *index + 1;
		length++;
	}
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, str + i, length + 1);
	return (result);
}

/**
 * countwords - counts nb of words separated by delimiter char c
 * @str: string to count words from.
 * @c:delimiter.
 * Return:nb of words separated by c + NULL
 */

int     countwords(char const *str, char c)
{
	int     i;
	int     count;
	int     trigger;

	trigger = 0;
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			if (trigger == 0)
			{
				trigger = 1;
				count++;
			}
		}
		else if (trigger == 1)
		trigger = 0;
		i++;
	}
	return (count + 1);
}

/**
 * ft_split - function that create sub strings from string str separated by c
 * @str : the string
 * @c: delimiter char.
 * Return:tab of strings.
 */

char    **ft_split(char const *str, char c)
{
	int             i;
	int             count;
	char    **res;
	int             index;

	if (str == NULL)
		return (NULL);
	count = countwords(str, c);
	res = (char **)malloc(sizeof(char *) * (count));
	if (res == NULL)
		return (NULL);
	index = 0;
	i = 0;
	while (i < count - 1)
	{
		res[i] = put(str, &index, c);
		i++;
	}
	res[i] = NULL;
	return (res);
}

