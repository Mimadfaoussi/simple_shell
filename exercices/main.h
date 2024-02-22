#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


char    **ft_split(char const *str, char c);
char    *ft_strjoin(char const *s1, char const *s2);
char	*_getenv(const char *name);
int _strlen(char *str);
#endif
