#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int _putchar(char c);
void print_error(int code, const char *msg, const char *arg);
void close_fd(int fd);

#endif /* MAIN_H */

