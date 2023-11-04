#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int	i;
	pid_t	pid[5];
	int	status;
	char	*argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	i = 0;
	while (i < 5)
	{
		pid[i] = fork();
		if (pid[i] == -1)
		{
			perror("Error\n");
			return(1);
		}
		if (pid[i] == 0)
		{
			printf("child number %d and pid = %u my father : %u\n", i, getpid(), getppid());
			if (execve(argv[0], argv, NULL) == -1)
				perror("error\n");
			return (0);
		}
		else
		{
			wait(&status);
			printf("----------------------------\n");
			printf("FATHER HERE : %u\n",getpid());
			printf("----------------------------\n");
			i++;
		}
	}
	printf("completed successfully \n");
	return (0);
}
