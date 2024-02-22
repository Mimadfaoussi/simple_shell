#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t	pid;
	int	status;

	printf("before creating the child %d\n",getpid());
	pid = fork();
	if (pid == -1)
		perror("error");
	if (pid == 0)
	{
		sleep(2);
		printf("i am child my pid is %d\n",getpid());
		sleep (3);
	}
	else
	{
		wait(&status);
		printf("i am the father %u\n",getpid());
	}
	//wait(&status);

	return (0);
}
