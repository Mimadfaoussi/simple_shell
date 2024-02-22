#include "main.h"



int main(int argc, char **argv)
{
	char		*path;
	char		**list;
	int		i;
	struct stat	statbuf;
	char		*file;
	char		*_argv;
	if (argc < 2)
	{
		printf("usage : %s filename ...\n",argv[0]);
		return (0);
	}
	path = getenv("PATH");
	list = ft_split(path, ':');
	i = 0;
	_argv = ft_strjoin("/",(const char *)argv[1]);
	while (list[i])
	{
		file = ft_strjoin((const char *)list[i], (const char *)_argv);
		if (stat(file, &statbuf) == 0)
		{
			printf("%s is correct\n",file);
		}
		else
		{
			printf("%s is not correct\n",file);
		}
		free(file);
		i++;
	}
	return (0);
}
