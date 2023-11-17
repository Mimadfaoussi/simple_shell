#include "shell.h"

/**
 * ft_strlcpy - Copies a string from source to destination.
 * @dst: Destination.
 * @src: Source.
 * @destsize: Destination size.
 * Return: Number of copied characters.
 */
size_t ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t i;
	size_t src_length;

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
 * put - Creates a string for split.
 * @str: String to work on.
 * @index: Where to start.
 * @c: Delimiter character.
 * Return: Created string.
 */
char *put(char const *str, int *index, char c)
{
	int i;
	int length;
	char *result;

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
 * countwords - Counts the number of words separated by delimiter character c.
 * @str: String to count words from.
 * @c: Delimiter.
 * Return: Number of words separated by c + NULL.
 */
int countwords(char const *str, char c)
{
	int i;
	int count;
	int trigger;

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
 * ft_split - Creates substrings from a string separated by c.
 * @str: The string.
 * @c: Delimiter character.
 * Return: Array of strings.
 */
char **ft_split(char const *str, char c)
{
	int i;
	int count;
	char **res;
	int index;

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
