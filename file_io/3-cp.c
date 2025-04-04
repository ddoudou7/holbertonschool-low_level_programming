#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

/**
* print_error - Print message to stderr and exit with code
* @code: exit code
* @msg: message to print
* @arg: argument (file name)
*/
void print_error(int code, const char *msg, const char *arg)
{
dprintf(STDERR_FILENO, msg, arg);
exit(code);
}

/**
* close_fd - Close file descriptor and check for error
* @fd: file descriptor
*/
void close_fd(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
* transfer - Perform the read/write loop
* @fd_from: source file descriptor
* @fd_to: destination file descriptor
* @file_from: source file name
* @file_to: destination file name
*/
void transfer(int fd_from, int fd_to,
const char *file_from, const char *file_to)
{
ssize_t r, w;
char buffer[BUF_SIZE];

while ((r = read(fd_from, buffer, BUF_SIZE)) != 0)
{
if (r == -1)
{
close_fd(fd_from);
close_fd(fd_to);
print_error(98,
"Error: Can't read from file %s\n", file_from);
}

w = write(fd_to, buffer, r);
if (w == -1 || w != r)
{
if (errno == EBADF || errno == EIO || r == -1)
{
close_fd(fd_from);
close_fd(fd_to);
print_error(98,
"Error: Can't read from file %s\n", file_from);
}
close_fd(fd_from);
close_fd(fd_to);
print_error(99,
"Error: Can't write to %s\n", file_to);
}
}
}

/**
* copy_file - Copy contents of one file to another
* @file_from: source file name
* @file_to: destination file name
*/
void copy_file(const char *file_from, const char *file_to)
{
int fd_from, fd_to;

fd_from = open(file_from, O_RDONLY);
if (fd_from == -1)
print_error(98, "Error: Can't read from file %s\n", file_from);

fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd_to == -1)
{
close_fd(fd_from);
print_error(99, "Error: Can't write to %s\n", file_to);
}

transfer(fd_from, fd_to, file_from, file_to);

close_fd(fd_from);
close_fd(fd_to);
}

/**
* main - Entry point
* @argc: argument count
* @argv: argument vector
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
if (argc != 3)
print_error(97, "Usage: cp file_from file_to\n", "");

copy_file(argv[1], argv[2]);
return (0);
}

