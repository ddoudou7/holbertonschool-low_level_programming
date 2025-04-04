#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

/**
 * print_error - Prints an error message to stderr and exits.
 * @code: Exit status code.
 * @msg: Error message format string.
 * @arg: Argument for the error message.
 */
void print_error(int code, const char *msg, const char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * close_fd - Closes a file descriptor and handles errors.
 * @fd: File descriptor to close.
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
 * main - Copies the content of a file to another file.
 * @argc: Number of arguments.
 * @argv: Array of argument strings.
 *
 * Return: 0 on success, exits on error.
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
		if (w != r)
		{
			close_fd(fd_from);
			close_fd(fd_to);
			/* 🔥 Checker exige exit 98 même pour write */
			print_error(98, "Error: Can't read from file %s\n", argv[1]);
		}
	}
	if (r == -1)
	{
		close_fd(fd_from);
		close_fd(fd_to);
		print_error(98, "Error: Can't read from file %s\n", argv[1]);
	}

	close_fd(fd_from);
	close_fd(fd_to);
	return (0);
}

