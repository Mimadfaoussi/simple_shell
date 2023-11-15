#include "shell.h"

/**
 * ft_strdup - create a string duplicate.
 * @str : string to create copy from
 * Return: string copy.
 */

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	while (str[i])
		i++;
	ptr = malloc(sizeof(char) * i + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/**
 * _reset - reset a string to '\0'
 * @fullpath: string to reset.
 * Return : void.
 */

void	_reset(char *fullpath)
{
	int     i;

	i = 0;
	while (fullpath[i] != '\0')
	{
		fullpath[i] = '\0';
		i++;
	}
}

/**
 * find_file_path - return full path of a file.
 * @filename : name of fiel to search for.
 * Return:full path string.
 */

char	*find_file_path(char	*filename)
{
	char	*path;
	char	**tokens;
	int	found;
	char	*fullpath;
	int	i;
	int	size;

	i = 0;
	size = 0;
	found = 0;
	path = getenv("PATH");
	tokens = ft_split((char const *)path, ':');
	if (access(filename, X_OK) == 0)
		return (filename);
	while (tokens[i] != NULL)
	{
		size = ft_strlen(tokens[i]) + ft_strlen(filename) + 2;
		fullpath = malloc(sizeof(char) * size);
		_reset(fullpath);
		ft_strlcat(fullpath, (const char *)tokens[i], 128);
		ft_strlcat(fullpath, (const char *)"/", 128);
		ft_strlcat(fullpath, (const char *)filename, 128);
		if (access(fullpath, X_OK) == 0)
		{
			found = 1;
			break;
		}
		i++;
		free(fullpath);
	}
	if (found)
		return (fullpath);
	return (NULL);
}
/**
 * fullpath - replacing the first element with program name only.
 * @list:list to change the first par for exceve.
 * Return : void.
 */

void	fullpath(char **list)
{
	char	*str;

	str = ft_strdup(list[0]);
	if (find_file_path(list[0]) != NULL)
	{
		free(list[0]);
		list[0] = find_file_path(str);
	}
}

