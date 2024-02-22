#include "main.h"

/**
 * _strlen-get length of a str
 * @str:the string to get length of 
 * Return:the length of string
 */

int _strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * _compare_env-compare the string provided with the env 
 * @env:an environement variable
 * @name:the name to check if exist
 * Return:1 if its the same otherwise 0
 */

int _compare_env(char *env, const char *name)
{
	int	i;
	int	len;

	i = 0;
	len = _strlen((char *)name);
	while (env[i] && name[i] && i < len)
	{
		if (env[i] != name[i])
			return (0);
		i++;
	}
	if (i == len)
		return (1);
	return (0);
}

char	*str_slice(char *str, char *name)
{
	int	i;
	int	len;
	char	*res;

	len = _strlen(str) - _strlen(name);
	res = malloc(len);
	if (!res)
		return (NULL);
	i = _strlen(name) + 1;
	len = 0;
	while (str[i])
	{
		res[len] = str[i];
		i++;
		len++;
	}
	res[len] = '\0';
	return (res);
}

/**
 * _getenv-get the environment variable if exist
 * @name:the name to check if its an env variable
 * Return:the env variable value or null if doesnt exist
 */

char *_getenv(const char *name)
{
	extern char** environ;

	int	i;

	i = 0;
	while (environ[i] != NULL)
	{
		if (_compare_env(environ[i], name) == 1)
			return (str_slice(environ[i], (char *)name));
		i++;
	}
	return (NULL);
}

/*
int main(void)
{
	int	i;

	//i = _compare_env("PATH:","PATH");
	printf("%s\n",_getenv("HOSTNAME"));
	printf("%s\n",getenv("HOSTNAME"));
	return (0);
}*/
