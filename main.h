#ifndef _SHELL_H_
#define _SHELL_H_
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int	_putchar(int c);
int     _putstr(char *str);
char    **ft_split(char const *str, char c);

#endif
