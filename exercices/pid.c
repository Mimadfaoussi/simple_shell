#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t	my_pid;

	my_pid = getppid();
	printf("my ppid %u and pid %u\n",my_pid, getpid());
	return (0);
}

