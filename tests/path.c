#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void find_file_path(char *filename)
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");
	int found = 0;
	printf("path = %s\n",path);
	//printf("%s\n",res[i]);
	while (token != NULL)
	{
		char full_path[1024];
		snprintf(full_path, sizeof(full_path), "%s/%s", token, filename);
		printf("\n\ndebugging %s : |%s|\n\n", token, full_path);
		if (access(full_path, X_OK) == 0)
		{
			printf("%s\n", full_path);
			found = 1;
			break;
		}
		token = strtok(NULL, ":");
		printf("token = %s",token);
	}
	if (!found)
		printf("%s not found in path\n", filename);
}

int main(int argc, char **argv)
{
	int i = 1;
	if (argc < 2)
	{
		printf("need filename\n");
		return (1);
	}
	while (i < argc)
	{
		find_file_path(argv[i]);
		printf("*************\n");
		i++;
	}
	return (0);
}
