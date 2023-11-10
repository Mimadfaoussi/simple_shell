#include "main.h"

void _reset(char *fullpath)
{
	int	i;

	i = 0;
	while (fullpath[i] != '\0')
	{
		fullpath[i] = '\0';
		i++;
	}
}

void find_file_path(char *filename)
{
        char 	*path;
        //char	*token;
	int	i;
	char	**tokens;
        int found;
	char	fullpath[128];

	found = 0;
	i = 0;
	path = getenv("PATH");
	tokens = ft_split((char const *)path, ':');
	while (tokens[i] != NULL)
	{
		_reset(fullpath);
		//printf("token %d = %s \n",i,tokens[i]);
		ft_strlcat(fullpath, (const char *)tokens[i],128);
		ft_strlcat(fullpath, (const char *)"/",128);
		ft_strlcat(fullpath, (const char *)filename,128);
		//printf("%s\n",fullpath);
		if (access(fullpath, X_OK) == 0)
		{
			printf("%s found in ----> %s\n",filename, fullpath);
			found = 1;
			break;
		}
		i++;
	}
        if (!found)
                printf("%s  not found in path\n",filename);
	return;
}

int main(int argc, char **argv)
{
	int	i;

        if (argc < 2)
        {
                printf("need filename\n");
                return (1);
        }
	i = 1;
	while (i < argc)
	{
		find_file_path(argv[i]);
		i++;
	}
	//printf("%s\n",getenv("PATH"));
        return (0);
}
