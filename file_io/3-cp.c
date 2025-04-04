#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

/**
 * print_error - Print message to stderr and exit with code
 * @code: exit status to return
 * @msg: error message to print
 * @arg: argument (filename)
 */
void print_error(int code, const char *msg, const char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * close_fd - Close a file descriptor and check for error
 * @fd: the file descriptor to close
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
 * main - Entry point, copies content of a file to another
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, exits with codes on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buffer[BUF_SIZE];

	if (argc != 3)
		print_error(97, "Usage: cp file_from file_to\n", "");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error(98, "Error: Can't read from file %s\n", argv[1]);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close_fd(fd_from);
		print_error(99, "Error: Can't write to %s\n", argv[2]);
	}

	while ((r = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
		{
			if (errno == EBADF || errno == EIO)
				print_error(98, "Error: Can't read from file %s\n", argv[1]);

			close_fd(fd_from);
			close_fd(fd_to);
			print_error(99, "Error: Can't write to %s\n", argv[2]);
		}
	}
	if (r == -1)
		print_error(98, "Error: Can't read from file %s\n", argv[1]);

	close_fd(fd_from);
	close_fd(fd_to);
	return (0);
}

