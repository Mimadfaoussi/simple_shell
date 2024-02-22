#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
	int	i;
	int	status;
	char	*str[] = {"/bin/ls","-l","/tmp/",NULL};
	pid_t	pid;

	i = 0;
	printf("i am the father %u\n",getpid());
	while (i < 5)
	{
		pid = fork();
		if (pid == 0)
		{
			printf("i am son %u  my father %u\n",getpid(),getppid());
			if (execve(str[0], str, NULL) == -1)
				perror("error :");
		}
		else
		{
			i++;
			wait(&status);
		}
	}
	return (0);
}
