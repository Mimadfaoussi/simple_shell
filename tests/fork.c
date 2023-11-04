#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
	pid_t	pid;
	int	status;

	printf("---------------Before start---------------");
	pid = fork();
	if (pid == -1)
	{
		perror("ERROR \n");
		return (1);
	}
	if (pid == 0)
	{
		printf("son pid is : %u and father : %u\n",getpid(),getppid());
		sleep(3);
	}
	else
	{
		wait(&status);
		printf("status is : %d and father pid is : %u\n", status, getpid());
	}
	return (0);
}
