#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

void _putchar(int c);
void _putstr(char *str);
void _error(void);
size_t ft_strlen(const char *s);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char **ft_split(char const *str, char c);
size_t ft_strlcpy(char *dst, const char *src, size_t destsize);
char *find_file_path(char *filename);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
void fullpath(char **list);

#endif
