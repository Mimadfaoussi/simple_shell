#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

void     _putchar(int c);
void     _putstr(char *str);
void    _error(void);

#endif
