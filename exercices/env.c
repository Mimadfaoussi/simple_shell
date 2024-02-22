#include <stdio.h>
#include <stdlib.h>

// Global variable extern declaration
extern char** environ;

int main(int argc, char **argv, char **envr) {
    // Pointer to iterate through the environment variables
    char** env = environ;

    // Print each environment variable
    /*while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }*/
    printf("environ = %p , envr = %p\n", env, envr);
    return 0;
}
